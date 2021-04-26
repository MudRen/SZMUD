// Code of ShenZhou
// pianting2.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ƫ��");
        set("long", @LONG
���ǻ�ɽ��Ժ��ƫ�����������򵥣�ֻ��һ�����Ӻͼ������ӣ�ǽ
�Ϲ��ż���ͼ�������ӵĶ����߸�Ϊ���������ǻ�ɽ���Ӿ��������ĵط���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"zoulang1",
            "south" : __DIR__"buwei2",
            "east" : __DIR__"liangong1",
            "west" : __DIR__"liangong2", 
        ]));

        set("objects", ([ 
            CLASS_D("huashan") + "/zhongze" : 1,
        ]));

        set("no_clean_up", 0);

        set("valid_startroom",1);

        set("cost", 0);
        setup();
}

void init()
{
        object ob, me=this_player();
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ( (!myfam || myfam["family_name"] != "��ɽ��") && !me->query_temp("bai_ning")
           && ob=present("ning zhongze", environment(me)) ) {
                message_vision("$Nŭ��������Ǻ��ˣ����ᴳ���������ˣ����ߣ�\n", ob);
        }

        add_action("do_kill","kill");
        add_action("do_hit","hit");
	add_action("do_throw","throw");
}

int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;

        if ( ob->query("family/family_name") == "��ɽ��" && me->query("family/family_name") != "��ɽ��" ) {
           message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);    
        
           if ( ob1=present("ning zhongze", environment(me)) ) {
                message_vision("$Nŭ��������д��������ڻ�ɽ����Ұ����ͼ����ɱ�ˣ�\n", ob1);
                ob1->kill_ob(me);
                return 1;
           }

           return 0;
        }
        else if ( ob->query("family/family_name") == "��ɽ��" && ob->query("id") != "yue buqun" 
        && ob->query("id") != "ning zhongze" && me->query("family/family_name") == "��ɽ��" ) {
           message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);

           if ( ob1=present("ning zhongze", environment(me)) ) {
                message_vision("$N����������Լ�ͬ�ž������ɱ�������ҵ�˼����ȥ�ú���ڷ�ʡ��\n", ob1);
                return 1;
           }

           return 0;
        }

        return 0;
}

int do_hit(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;

        if ( ob->query("family/family_name") == "��ɽ��" && me->query("family/family_name") != "��ɽ��" ) {
           message_vision("$n����$N���һ�������У�\n",ob, me);

           if ( ob1=present("ning zhongze", environment(me)) ) {
                message_vision("$Nŭ��������д��������ڻ�ɽ����Ұ����ͼ����ɱ�ˣ�\n", ob1);
                ob1->kill_ob(me);
                return 1;
           }

           return 0;
        }
        else if ( ob->query("family/family_name") == "��ɽ��" && ob->query("id") != "yue buqun"
        && ob->query("id") != "ning zhongze" && me->query("family/family_name") == "��ɽ��" ) {
           message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);

           if ( ob1=present("ning zhongze", environment(me)) ) {
                message_vision("$N����������Լ�ͬ�ž������ɱ�������ҵ�˼����ȥ�ú���ڷ�ʡ��\n", ob1);
                return 1;
           }

           return 0;
        }

        return 0;
}

int do_throw(string arg)
{
	object victim, ob1, ob, me = this_player();
	string what, who;

	if( !arg
        ||      sscanf(arg, "%s at %s", what, who)!=2)
                return notify_fail("�����ʽ: throw <��Ʒ> at <ĳ��>��\n");

	ob = present(what, me);
        if( !ob ) ob = present(arg, environment(me));
	if( !ob ) return notify_fail("��Ҫ��ʲô��\n");

        if (ob->query("no_drop"))
                return notify_fail("������������뿪�㡣\n");

        if (!(victim = present(who, environment(me))))
                return notify_fail("����û�����Ŀ�ꡣ\n");

        if (!victim)
                return notify_fail("���ﲢ�޴��ˣ�\n");

        if (!living(victim))
                return notify_fail("�ⲻ�ǻ��\n");
	
	if ( victim->query("family/family_name") == "��ɽ��" && me->query("family/family_name") != "��ɽ��" ) {
	   message_vision("$n����$N���һ�������У�\n",victim, me);

	   if ( ob1=present("ning zhongze", environment(me)) ) {
		message_vision("$Nһ����Ц���󵨿�ͽ�������ڻ�ɽ��͵Ϯ���ˣ����һ�ɽ�ɺ��۸�ô��\n", ob1);
		ob1->kill_ob(me);
		return 1;
	   }

	   return 0;
	}
	else if ( victim->query("family/family_name") == "��ɽ��" && victim->query("id") != "yue buqun"
	&& victim->query("id") != "ning zhongze" && me->query("family/family_name") == "��ɽ��" ) {
	   message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", victim, me);

	   if ( ob1=present("ning zhongze", environment(me)) ) {
		message_vision("$N���ô������Խ��Խ�г�Ϣ�ˣ��Լ�ͬ�ž������ɱ�����Ҷ���˼����ȥ��ڣ�\n", ob1);
		return 1;
	   }

	   return 0;
	}

	return 0;
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ( (!myfam || myfam["family_name"] != "��ɽ��") && dir != "north" 
           && present("ning zhongze", environment(me)) ) {
                return notify_fail("��������������ǰ��������˲������׳��뱾���صأ�����������뿪��\n");
        }

        return ::valid_leave(me, dir);
}