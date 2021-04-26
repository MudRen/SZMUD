inherit NPC; 
#include <ansi.h>

string *ras_name = ({
        "��å",
        "����",
        "��Ʀ",
        "���ְ���",
        "С���",
        "��ͽ",
        "����", 
});
 string *ras_id = ({
        "liu mang",
        "wu lai",
        "di pi",
        "wulin bailei",
        "xiao hunhun",
        "pan tu",
        "lang ren",     
});      
string *persuade_msg = ({
        "�����˴������ˣ�ʩ�����ǰ��ֲ����˰ɣ�\n", 
        "����ˣ��л���˵����Ҫ������ᣡ\n",
        "��λ�ݵ����˺�������Ҫ�ٶ���ȥ�˰ɣ�\n",
        "�����ӷ𣬴�ҽ�����ʿ�����ؾͶ����������λ����ס�ְɣ�\n",
        "ס�ְգ������ԩ�޳𣬺α�ʧ�������еĺ�����\n",
        "������Ѷ���·, ��λ�β����ɸ�Ϊ��, ͣ�ְն�����Ϊ���أ�\n",
        "�������Ҫ�㵽Ϊֹ���αؿ���භ�����������Լ�������\n",
});
string *succeed_msg = ({
        "������Ȱ�����Ұ���, ���º�����ڡ�\n",
        "�ڴ���Ȱ�������˼ҵ������ϣ���ξ�����....������ڡ�\n",
});

string  ask_per();

int do_quanfu(string);
int     per_end(object,object);
void dest_ob(object);


void create() 
{
        string a,b;
        int     i;
        i = random(7);
        a = ras_name[i];
        b = ras_id[i];
 
        set_name(a,({b})); 
        set("long","����һ�����δ󺺡�\n"); 
        set("age",25); 
        set("shen_type",-1); 
        set("shen",-2000); 
        set( "str", 25 ); 
        set( "con", 20 ); 
        set( "int", 10 ); 
        set( "dex", 20 ); 
      
        set_skill("strike",20); 
        set_skill("force",20); 
        set_skill("dodge",20); 
        set_skill("parry",20); 
      
        set("combat_chat_chance",5); 
        set("inquiry",([
                "Ȱ��" : (:ask_per:),
        ]));

        setup(); 
        add_money("silver",30); 
} 
void init()
{
        add_action("do_quanfu","quanfu");
}

int do_quanfu(string who)
{
        object me = this_player();
        object target;
        object where = environment(me);
        int     lvl=me->query_skill("persuading",1);
        mixed busy;
        
        if (me->query("family/family_name")!="������") {
                command ("grin");
                return notify_fail("��Ҳ��Ȱ����\n");
       }
        if (me->query_temp("mp_persjob")==2)
                return notify_fail("���ȥ�����ʦ̫�����ɡ�\n");
        
        if ( me->query_temp("mp_persjob") != 1)
                return notify_fail("���ڸ�ʲô��\n");

        
        if (!who)
                return notify_fail("��ҪȰ��˭��\n");
        
        target = present(who, environment(me));
        if ( !target || target == me || !living(target) || !objectp(target) ) 
                return notify_fail("����Ȱ��˭��\n");

        if ( busy = me->query_busy() ) {
                if (intp(busy) && busy<3) me->start_busy(busy+1);
                return notify_fail("��������æ�ţ�\n");
        }
        
        if ( target->query("race") != "����" )
                return notify_fail(target->name() + "�������˻���\n");

        if ( target->query("per_mark")!=me)
                return notify_fail("���ʦ̫��������Ȱ������˰ɡ�\n");

        if ( me->query_temp("new_per") == 1)
                return notify_fail("������Ȱ�����ˡ�\n");

        if (me->query("jingli") < lvl || me->query("jing")<lvl)
                return notify_fail("�������״�����ã�û������Ȱ���ˡ�\n");

       tell_object(me, HIY + "���" + EMOTE_D->normal_color(target->name())
              + "˵����" + persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR); 

       tell_object(target, HIY + me->name() + "����˵����" +
                persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR);

       message("vision", HIY + me->name() + "��" + EMOTE_D->normal_color(target->name()) 
                + "˵����" + persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR,
                where, ({ me, target }) );


        me->set_temp("new_per",1);
        if (me->query("combat_exp") < 100000)
        {
                me->add("jingli",-random(10));
        
        }
        else
        {
                me->add("jingli",-(10+random(lvl)));
                me->add("jing",-(10+random(lvl)));
        }
        if (!target->is_fighting())
        {
                message_vision(HIR"$N�ٺ�һЦ������ʲô��������Ȱ����? ���������㡣\n"NOR,target,me);
                target->kill_ob(me);
        }
        call_out("per_end",2+random(4),me,target);


        return 1;
}

int     per_end(object me,object target)
{
        int lvl = me->query_skill("persuading",1);
        int myexp = me->query( "combat_exp" ); 
        int level = to_int(pow(myexp*10,0.33333)+1); 

        if (environment(target) != environment(me)) {
                tell_object(me, "���գ�" + target->name() + "�Ѿ����ˡ�\n"); 
                me->delete_temp("new_per");
                return 1;
        }

        if ( !living(target) || !target ) {
                tell_object(me, target->name() + "�Ѳ�����ȡ���Ȱ���ˣ�\n");
                me->delete_temp("new_per");
                return 1;
        }


        if (random(lvl/2) > random(level) || random(15) == 0)
        {
                tell_object(target, HIG + "���ܵ�" + me->name()
                                  + "�ĸ��У��������ֲ�����\n" + NOR);
                tell_object(me, HIG + EMOTE_D->normal_color(target->name()) 
                              + "�ܵ���𷨸��У��������ֲ�����\n" + NOR);
              message("vision", CYN"ֻ��" + EMOTE_D->normal_color(target->name()) 
                        + "����һ�ݣ�˵�����ã�" + me->name() 
                        + succeed_msg[random(sizeof(succeed_msg))] + NOR, 
                        environment(target), ( {me, target} ) );

                tell_object(me,HIW"��������Ѿ���ɣ����ȥ�����ʦ̫����ȥ�ɡ�\n"NOR);
                target->remove_all_killer();
                me->improve_skill("persuading",random(lvl));
                me->delete_temp("new_per");
                me->set_temp("mp_persjob",2);
                call_out("dest_ob",1,target);



        }
        else
        {
                tell_object(me, RED + EMOTE_D->normal_color(target->name()) + "������һ������"
                                       + RANK_D->query_rude(me) 
                                       + "������£����У���\n" + NOR);
                tell_object(target, CYN + "���" + me->name() + "���һ������"
                                          + RANK_D->query_rude(me)
                                          + "������£����У���\n" + NOR);
                message("vision", CYN + "ֻ��" + EMOTE_D->normal_color(target->name()) + "����"
                                        + me->name() + "���һ������"
                                        + RANK_D->query_rude(me)
                                        + "������£����У���\n" + NOR, environment(target),
                                        ( {me, target} ) );
                me->delete_temp("new_per");

        }
        me->start_busy(1+random(1));
        return 1;
}

string ask_per()
{
        object ob=this_object();
        object  me=this_player();

        if (ob->query("per_mark") == me)
        {
                ob->kill_ob(me);
                return "����ʲô�������Ҷ�����Ȱ�ܡ�";
        }
        else
        {
                command("idle");
                return "���ʲô��������������˵ʲô��";
        }

}

void dest_ob(object target)
{
        destruct(target);
}
      
