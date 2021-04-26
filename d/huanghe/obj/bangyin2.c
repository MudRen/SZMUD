// Code of ShenZhou
// /d/changbai/bj/bangyin2.c ��ӡ
// by aln 1 / 98
// modified by aln 4 / 98

#define KILLER  "/d/huanghe/npc/killer"
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("��ӡ", ({ "bangyin" }) );
        set("weight", 30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 30);
                set("material", "wood");
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
        }

        setup();

        call_out("message_killer", 20 + random(20));
}

void message_killer()
{
        object ling, owner, env, *enemy, killer_ob;
        string region, bang;
        int i, danger, bonus;

        call_out("message_killer", 10 + random(10));

        if( !(owner = query("owner")) ) {
                destruct(this_object());
                return;
        }

        if( !(ling = present("taishan ling", owner)) ) {
                owner->delete_temp("apply/short");
                owner->delete_temp("fam");
                tell_object(owner, HIR"\n���̩ɽ��㶪�ˣ�̩ɽ�йٸ��ջذ�ӡ��\n\n"NOR);
                destruct(this_object());
                return;
        }

        if( (string)ling->query("job/type") != "����" ) {
                owner->delete_temp("apply/short");
                owner->delete_temp("fam");
                tell_object(owner, HIR"\n�����Ե��ΰ�����̩ɽ�йٸ��ջذ�ӡ��\n\n"NOR);
                destruct(this_object());
                return;
        }

        if( environment() != owner ) {
                owner->delete_temp("apply/short");
                owner->delete_temp("fam");
                ling->delete("job");
                if( environment()->is_character() )
                tell_object(environment(), HIR"\n��ͻȻ������ӡ�����ˣ�\n\n"NOR);
                destruct(this_object());
                return;
        }

        env = environment(owner);
        if( env->query("no_fight") )
                return;

        region = explode(base_name(env), "/")[1];
        if( region == "city" || region == "wudang" )
                return;

   // let players walk around, do not always stay in one region as a bangzhu
        if( region == (string)ling->query("job/region") )
                ling->add("job/idle", 1);
        else {
                ling->set("job/region", region);
                ling->delete("job/idle");
        }

        if( (int)ling->query("job/idle") > owner->query("kar")/2 ) {
                owner->delete_temp("apply/short");
                owner->delete_temp("fam");
                ling->delete("job");
                tell_object(owner, HIR"\n��ͻȻ������ӡ�����ˣ�\n\n"NOR);
                destruct(this_object()); 
                return;
        }

        enemy = owner->query_enemy();
        danger = 0;
        if( sizeof(enemy) ) {
        for(i= 0; i < sizeof(enemy); i++) {
                if( enemy[i]->query("victim") != owner )
                        continue;
                if( enemy[i]->is_busy() )
                        continue;
                if( !enemy[i]->is_fighting(owner) )
                        continue;
                if( (int)enemy[i]->query("eff_qi") < 200 )
                        continue;
                if( (int)enemy[i]->query("jingli") < 100 )
                        continue;
                if( (int)enemy[i]->query("neili") < 50 )
                        continue;

                danger++;
        }
        }

        if( danger < 1 ) {
                killer_ob = new(KILLER);
                killer_ob->set("victim", owner);

                bang = (string)query("fam");
                killer_ob->set("bang", bang);
                killer_ob->set("inquiry/" + bang,  "�����뵱" + bang + "������������ˣ�����");
                killer_ob->set("inquiry/" + "��ӡ", "����Ҫ�ľ���" + "�İ�ӡ��");
                killer_ob->set("combat_exp", (int)owner->query("combat_exp") - 1000);
                killer_ob->move(env);
                message_vision("$N���˹�����\n", killer_ob);
                message_vision("$N����$nһ�ۡ�\n", killer_ob, owner);
                killer_ob->set_leader(owner);
                remove_call_out("do_kill");
                call_out("do_kill", 1, killer_ob, owner);

                return;
        }

        if( danger > 5 ) danger = 5;
        bonus = danger * (int)owner->query("combat_exp")/500;
        bonus += random(bonus);
        owner->add("shen", bonus);
}

void do_kill(object killer_ob, object owner)
{
        message_vision("$N��$n�����ȵ���" + RANK_D->query_rude(owner) + "���Ͽ�Ѱ�ӡ�������ӣ�����\n", killer_ob, owner);
        killer_ob->kill_ob(owner);
}
