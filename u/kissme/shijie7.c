// Code of ShenZhou
// Room: /d/shaolin/shijie7.c
// Modified by Apache

#include <ansi.h>
void arguing(object me, object ob, int question);
inherit ROOM;

void create() {
    set("short", "ʯ��");
	
	set("long", @LONG
ʯ�������������죬�ٲ��ڽ���Խ��ԽС��ˮ��Ҳ����Զȥ
��λ���Żһ�ɫɮ�µ�ɮ�˲����������������ɽ��ʱ��Ų���
�ȣ������Ǹ�����ӡ�����Զ�����ƺ����Կ���ʯ��һ�ǡ�����
���Ͼ�Ҫ�������ˣ�Ϊ�˲�����������徻���㲻�ò������˽�
����
LONG
	);
	
	set("exits", ([
		"southdown" : __DIR__"shijie6",
		"east" : __DIR__"shanmen",
	]));

	set("outdoors", "shaolin");
	set("cost", 40);
	setup();
}

void init() {
    object challenger, me = this_player();

    if ( me->query("family/family_name") == "������" && me->query("family/generation") < 38
         && random(5) == 2 && !present("sengren", environment(me)) ) {
        message_vision(HIR "ʯ���ԱߵĲݴ��к�ȻԾ��һ����Ӱ����ס��$N��\n" NOR, me);
        challenger = new(__DIR__"npc/challenger");
        challenger->move(environment(me));
        me->set_temp("challenged", 1);
        me->set_temp("challenger", challenger);
    }

    add_action("do_argue", "argue");
    add_action("do_giveup", "giveup");
}

int do_argue(string arg) {
    object ob, me = this_player();
    int count;

	if( me->query("family/family_name") != "������" )
	    return notify_fail("����ɽ��ǰ�������������£�\n");

    if( !arg )
        return notify_fail("����˵��˭��\n");

    if( !(ob = present(arg, environment(me))) )
        return notify_fail("���û����Ҫ˵�����ˡ�\n");

    if( me->query("family/generation") > 37 )
        return notify_fail("��ı��ݻ�������\n");

    if( !me->query_temp("challenged") )
        return notify_fail("���ֵ�������Զ�ȡʤ��\n");

    if( me->is_fighting() || me->is_busy() )
        return notify_fail("����æ�š�\n");

    if( ob->query("race") != "����" )
        return notify_fail(ob->name() + "�������˻���\n");

    if( ob->is_fighting() || ob->is_busy() )
        return notify_fail(ob->name() + "��æ�š�\n");

    if( userp(ob) )
        return notify_fail("����������Ƶ����������˵��ɡ�\n");

    if( ob->query_temp("opponent") != me )
        return notify_fail("�˼Ҳ������㣡\n");

    if ( !(me->query_temp("argued")) ) {
        me->set_temp("argued", 1);
        message_vision("\n$N˵����������٢�𣡳����˴ȱ�Ϊ����ϰ��ֻ��ǿ���塣��\n", me);
        message_vision("$N˵������Сɮ���ֽ�һЩ�𷨣���֪��ʦ�Ƿ�Ը��ָ��һ������\n", me);
        call_out("arguing", 1, me, ob, 0);
        me->start_busy(2);
    }
    else {
        count = me->query_temp("argued");
        if (count > 3)
            return notify_fail("������û��ʲô�������ѵ�������������취�ɡ�\n");
        if (count == 1) {
            switch (random(5)+1) {
            case 1:
                message_vision("\n$N�ʵ����������򡹺ν⣿��\n", me);
                call_out("arguing", 3, me, ob, 11);
                break;
            case 2:
                message_vision("\n$N�ʵ����������򡹺ν⣿��\n", me);
                call_out("arguing", 3, me, ob, 12);
                break;
            case 3:
                message_vision("\n$N�ʵ�����Ϊ����ӣ������ҹ����������˴��˾�����Ϊ��һ���򣿡�\n", me);
                call_out("arguing", 3, me, ob, 13);
                break;
            case 4:
                message_vision("\n$N�ʵ�����Ϊ����ӣ������ҹ����������˴��˾�����Ϊ�ڶ���֪����\n", me);
                call_out("arguing", 3, me, ob, 14);
                break;
            case 5:
                message_vision("\n$N�ʵ�����Ϊ����ӣ������ҹ����������˴��˾�����Ϊ������֪����\n", me);
                call_out("arguing", 3, me, ob, 15);
                break;
            }
        }
        if (count == 2) {
            switch (random(5)+1) {
            case 1:
                message_vision("\n$N�ʵ�����Ϊ����ӣ������ҹ����������˴��˾�����Ϊ���ľ�֪����\n", me);
                call_out("arguing", 3, me, ob, 21);
                break;
            case 2:
                message_vision("\n$N�ʵ�����Ϊ����ӣ������ҹ����������˴��˾�����Ϊ������򣿡�\n", me);
                call_out("arguing", 3, me, ob, 22);
                break;
            case 3:
                message_vision("\n$N�ʵ�����Ϊ����ӣ������ҹ����������˴��˾�����Ϊ������֪����\n", me);
                call_out("arguing", 3, me, ob, 23);
                break;
            case 4:
                message_vision("\n$N�ʵ�����������ʮ��Ϊ�񣬺ε�Ϊʮ����\n", me);
                call_out("arguing", 3, me, ob, 24);
                break;
            case 5:
                message_vision("\n$N�ʵ������ᱲ���ӣ��������ȣ���Ϊ���ȣ���\n", me);
                call_out("arguing", 3, me, ob, 25);
                break;
            }
        }
        if (count == 3) {
            switch (random(5)+1) {
            case 1:
                message_vision("\n$N�ʵ�����Ϊ����ӣ������ҹ����������˴��˾�����Ϊ���߾��򣿡�\n", me);
                call_out("arguing", 3, me, ob, 31);
                break;
            case 2:
                message_vision("\n$N�ʵ�����Ϊ����ӣ������ҹ����������˴��˾�����Ϊ�ڰ˾�֪����\n", me);
                call_out("arguing", 3, me, ob, 32);
                break;
            case 3:
                message_vision("\n$N�ʵ�������Ϊ�޳�����\n", me);
                call_out("arguing", 3, me, ob, 33);
                break;
            case 4:
                message_vision("\n$N�ʵ������Ժ���Ե����֪������������������\n", me);
                call_out("arguing", 3, me, ob, 34);
                break;
            case 5:
                message_vision("\n$N�ʵ���������Ϊ�ƣ�������󣿡�\n", me);
                call_out("arguing", 3, me, ob, 35);
                break;
            }
        }
        me->add("jing", -200+random(30));
        me->add("jingli", -200+random(30));
        me->start_busy(3+random(2));
        count++;
        me->set_temp("argued", count);
    }

    return 1;
}

void arguing(object me, object ob, int question) {
    int my_bud, ob_bud, bonus;
    mapping learned;

    if( !objectp(ob) ) return;

    if( question == 0) {
        message_vision("\n$N��ͷ���������������ʦӡ֤�𷨡���\n", ob);
        return;
    }

    my_bud = me->query_skill("buddhism", 1);
    ob_bud = ob->query_skill("buddhism", 1);
    learned = me->query_learned();

    if ( (my_bud > ob_bud) && ((my_bud - ob_bud) > random(40)) ) { /* bonus for 120 < bud_lvl < 160 */
        learned["buddhism"] += 200 + random(50);
		if(my_bud > 400) /*higher buddhism can gain more*/
		learned["buddhism"] += 100 + random(60);
        bonus = 40 - (my_bud - ob_bud);
        if (bonus < 0) bonus = 0; /* any one with buddhism > 160 can not get bonus at all. */
        bonus = bonus/2 + random(bonus/2);
        //message("info", sprintf("bonus %d\n", bonus), environment(me), 0);
        me->add("combat_exp", bonus*3);
        me->add("potential", bonus);
        if ( me->query("potential",1) > me->query("max_potential",1) )
            me->set("potential", me->query("max_potential",1) );
       	log_file("/job/sl-seng",sprintf("[%s] %s(%s) ���۷𷨵õ� %d ����� %d Ǳ�ܡ�\n", ctime(time()) ,me->name(), getuid(me), bonus*3, bonus )); //add log file.    
        message_vision("\n$NĬ����������Ȼ�����ɫ��һ��������뿪�ˡ�\n", ob);
        destruct(ob);
        me->delete_temp("challenged");
        me->delete_temp("challenger");
        me->delete_temp("argued");
        return;
    }
    else if ( (my_bud < ob_bud) && (random(40) > (ob_bud - my_bud)) ) { /* bonus for bud_lvl < 120*/
        learned["buddhism"] += 200 + random(50);
        bonus = ob_bud - my_bud;
        if (bonus == 0) bonus = random(20); /* for bud_lvl = 120 */
        bonus = bonus/2 + random(bonus/2);
        //message("info", sprintf("bonus %d\n", bonus), environment(me), 0);
        me->add("combat_exp", bonus*3);
        me->add("potential", bonus);
        if ( me->query("potential",1) > me->query("max_potential",1) )
            me->set("potential", me->query("max_potential",1) );
       	log_file("/job/sl-seng",sprintf("[%s] %s(%s) ���۷𷨵õ� %d ����� %d Ǳ�ܡ�\n", ctime(time()) ,me->name(), getuid(me), bonus*3, bonus )); //add log file.   
        message_vision("\n$NĬ����������Ȼ�����ɫ��һ��������뿪�ˡ�\n", ob);
        destruct(ob);
        me->delete_temp("challenged");
        me->delete_temp("challenger");
        me->delete_temp("argued");
        return;
    }

    switch(question) {
    case 11:
        message_vision("\n$NӦ��������һ�ŷ�����֪���̱��գ��������У��������򣬶����������\n", ob);
        break;
    case 12:
        message_vision("\n$NӦ�����������Ŷ��⣬����У��ж�֤���εڽ��ޣ�Ҳ�����롣��\n", ob);
        break;
    case 13:
        message_vision("\n$NӦ�������������޳�������Σ�࣬�Ĵ��գ��������ң�������죬��α������  ���Ƕ�Դ����Ϊ��޴�����ǹ۲죬������������\n", ob);
        break;
    case 14:
        message_vision("\n$NӦ������������Ϊ�࣬����ƣ�ͣ���̰����������Ϊ���������ڡ���\n", ob);
        break;
    case 15:
        message_vision("\n$NӦ���������������㣬Ω�ö������������������������֪�㣬��ƶ�ص���Ω����ҵ����\n", ob);
        break;
    case 21:
        message_vision("\n$N��һ��˼��΢Ц������и��׹�䣬���о������Ʒ��ն񣬴ݷ���ħ�������������̻�һ�У�Ϥ�Դ��֡���\n", ob);
        break;
    case 22:
        message_vision("\n$N��һ��˼��΢Ц�������޳����������������ѧ���ʣ������ǻۣ��ɾͱ�ţ��̻�һ�У�Ϥ�Դ��֡���\n", ob);
        break;
    case 23:
        message_vision("\n$N��һ��˼��΢Ц������ƶ���Թ������Ե��������ʩ������Թ�ף�����ɶ񣬲������ˡ���\n", ob);
        break;
    case 24:
        message_vision("\n$N��һ��˼��΢Ц������������ɱ�������������ģ����ࡢ��ڡ����ԡ����������������ա���\n", ob);
        break;
    case 25:
        message_vision("\n$N��һ��˼��΢Ц��������ʩ���ֽ䡢���衢������һ�ġ��ǻۡ���\n", ob);
        break;
    case 31:
        message_vision("\n$N��˼���ã�������������������Ϊ���ˣ���Ⱦ���֣��������£��߲�������  ־Ը���ң��ص���ף����и�Զ���ȱ�һ�С���\n", ob);
        break;
    case 32:
        message_vision("\n$N��˼���ã�������������Ȼ������������������ģ��ռ�һ�У�Ը���������������࣬�����������Ͼ����֡���\n", ob);
        break;
    case 33:
        message_vision("\n$N��˼���ã�������ɫ��ʹ���롢�С�ʶ����Ϊ�޳�����\n", ob);
        break;
    case 34:
        message_vision("\n$N��˼���ã�������������־���ɻ�������Ʃ��ĥ������ȥ���棻�������󣬵�����������\n", ob);
        break;
    case 35:
        message_vision("\n$N��˼���ã��������е��������ơ�־������ߴ󡣡�\n", ob);
        break;
    default:
        ;
    }

    return;
}


int do_giveup() {
    object ob, me = this_player();

    if ( me->query_temp("challenged") && present(me->query_temp("challenger"), environment(me)) ) {
        ob = me->query_temp("challenger");
        if ( !ob->query_temp("fought") ) {
            message_vision("\n$N��Ц���������ֺ��и�������̰������֮������\n", ob);
            me->add("combat_exp", -random(20));
        }
        me->delete_temp("challenger");
        me->delete_temp("challenged");
        message_vision("\n$N�뿪�ˡ�\n", ob);
        destruct (ob);
    }
    else
        return notify_fail("ʲô��");

    return 1;
}            
        
int valid_leave(object me, string dir) {
    object ob;

    ob = me->query_temp("challenger");


    if ( me->query_temp("challenged") && objectp(ob) && me == ob->query_temp("opponent") )
        return notify_fail("���ֵ������̰����������׹����������\n");
    else { 
        me->delete_temp("challenged");
        me->delete_temp("challenger");
        me->delete_temp("argued");
    }
        return ::valid_leave(me, dir);
}

