// Code of ShenZhou
// /d/huanghe/obj/caili.c  ����
// by aln 2 / 98

#define BANGZHONG2 "/d/huanghe/npc/bangzhong2"

#include  <ansi.h>
#include <command.h>

inherit ITEM;

#include "/d/huanghe/doc/info_bang.h"

void create()
{
        set_name(RED"����"NOR, ({ "caili" }));
        set("weight", 20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
"����һ�ݰ�װ���ƵĲ�������һ��װ�Ź��صĶ�����\n");
                set("unit", "��");
                set("value", 30);
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");            
        }

        setup();

        call_out("do_check", 1 + random(5));
}


// to avoid players from cheating
// like go by da che or let other players carry them
// like go by following another player or driven by another player

// i still think, it is better to change follow.c and sing.c files
// then will save source

void do_check()
{
        object owner, room;

        add_action("do_gu","gu");
        add_action("do_gu","hire");
        add_action("do_gu","qu");
        if( !(owner = query("owner")) ) {
                destruct(this_object());
                return;
        }

        if( owner->query_leader() ) {
                tell_object(owner, HIR"\n���Ȼ��һ�ֲ���ĸо���\n"NOR);
                destruct(this_object());
                return;
        }

        call_out("do_check", 1 + random(3));
}

void init()
{
        add_action("do_go", "go");
        add_action("do_visit", "visit");
        add_action("do_visit", "song");
        add_action("do_giveup", "giveup");
        add_action("do_gu","gu");
        add_action("do_gu","hire");
        add_action("do_gu","qu");
}

int do_gu(string arg)
{
	write("��͵�����㻹�ǿ��Լ��߹�ȥ�ɡ�\n");
	return 1;
}

int do_go(string arg)
{	int jl;
        object me = this_player(), ob, room;
        string *bangs;
        int ap, dp,exp;

        if( me->is_busy() ) {
                write("����æ�š�\n");
                return 1;
        } 

        room = environment(me);

        if( ob = present("bang zhong", room) ) {
                if( living(ob) ) {
                        ap = (int)me->query("combat_exp");
                        dp = 6 * (int)ob->query("combat_exp");
     // leave a trick here for smarter players
                        if( random(15) == 0 )
                                return notify_fail("");

                        me->start_busy(1);
                        message_vision("$N��$n�ȵ���" + RANK_D->query_rude(me) + "�Ѷ������£�����\n", ob, me);
                        if( !ob->is_fighting(me) )
                                ob->kill_ob(me);
                        return 1;
                }
        }

        if( random(8) ) {
                jl=me->query("jingli")/50;
                me->receive_damage("jingli", jl , "��������");
                return notify_fail("");
        }

        ob = new(BANGZHONG2);
        exp=me->query("combat_exp");
        exp=exp/2+random(exp/5*3);
        ob->setsk(exp);
        bangs = keys(info_bang);
        bangs -= ({(string)me->query_temp("bangs/name")});
        ob->set("title", bangs[random(sizeof(bangs))]);

        ob->move(room);
        message("vision",
                ob->query("title") + ob->name() + "���˹�����\n",
                environment(ob), ({ob}));
        message_vision(HIR"\n" + ob->query("title") + ob->name() + "��$N�ȵ���" + RANK_D->query_rude(me) + "�Ѷ������£�����\n"NOR, me);    
        ob->kill_ob(me);
        me->start_busy(1);
        return 1; 
}

int do_visit(string arg)
{
        object room, ob, me = this_player(), obj;
        int bonus, record,addscore;
        mapping job;

        if( me->is_busy() || me->is_fighting() ) {
                write("����æ�š�\n");
                return 1;
        }

        if( !arg ) {
                write("��Ҫ�ݷ�˭��\n");
                return 1;
        }

        if( !mapp(job = query("job")) ) {
                destruct(this_object());
                return 1;
        }

   // the following is very important to avoid players cheating
        room = environment(me);
        if( base_name(room) != job["file"] ) {
                write("�㻹û��Ŀ�ĵ��ء�\n");
                return 1;
        }

        if( !(ob = present(arg, room)) ) {
                write("���û����Ҫ�ݷõ��ˡ�\n");
                return 1;
        }

        if( ob->query("name") != job["name"] ) { 
                write("��ݷô����ˡ�\n");
                return 1;
        }

        if( !living(ob) ) {
                write("�㻹�ǵȴ���������˵�ɡ�\n");
                return 1;
        }

        if( ob->is_busy() || ob->is_fighting() ) { 
                write("������æ�š�\n");
                return 1;
        }

        message_vision("$N��$n�������˸�Ҿ������˵�����װ������" + RANK_D->query_self_rude(me) + "��һ�ݴ����" + RANK_D->query_respect(ob) + "��\n", me, ob);
        message_vision("$N��" + name() + "˫�ַ��$n��\n", me, ob);
        move(ob);
        remove_call_out("do_destroy");
        call_out("do_destroy", 1, this_object());

        message_vision("$N����һ����˵����" + RANK_D->query_respect(me) + "�����ˡ���ȥ�������������ʸ�����\n", ob);

        bonus = 130 + random(40);
        addscore=me->query("clbscore")/5000;
        if (addscore>30) addscore=30;
        bonus = bonus + addscore;
        
        record = bonus * 3 + random(bonus/2);
        me->add("combat_exp", record);
        write_file("/log/test/BangJob", sprintf("%s��%sʱ�������%s�����\n", me->query("name"), ctime(time()), chinese_number(record)));
       
        if( obj = present("bang ling", me) ) {
                if( obj->query("owner") == me->query("id") )
                        obj->delete("job");
                        tell_object(me,HIW"����ι������õ�"+chinese_number(bonus)+"�㹦�͵㣬" + chinese_number(record)+ "�㾭��ֵ��\n"NOR);
                        me->add("clbscore",bonus);
        }
        return 1;
}

void do_destroy(object ob)
{
        if(ob) destruct(ob);
}

int do_giveup()
{
        object ob;

        if( ob = present("bang zhong", environment(this_player())) ) {
                if( base_name(ob) == BANGZHONG2 && living(ob) ) {
                message_vision("$N����ʧ���س�̾һ����˵������Ȼ��ˣ�Ҳ�Ͱ��ˣ�\n", this_player());
                message_vision("$N�������͸�$n��\n", this_player(), ob);
                message("vision",
                ob->name() + "˵��������ʶʱ���Ҿ�����һ����˵����ﳤ��ȥ��\n",
                environment(ob), ({ob}));
                destruct(ob);
                destruct(this_object());
                return 1;
                }
        }
        return 1;
}
