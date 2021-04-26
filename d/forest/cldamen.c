// Code of ShenZhou
// /d/huanghe/changle/cldamen.c
// aln  2 / 98

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������ϵĳ��ְ��ܶ����ڡ��ǳ��ְ��ڽ��������Ʒ�ͬС      
�ɣ������������ս����������Ⱥ�������϶��������Ļ�ͷ������������    
��İ���վ�����ࡣ������һ������(bian)����յ�����������ҡ�ڡ���  
����һ����(bei) ���������һЩ���֡�
LONG );

        set("exits", ([
		"enter" : __DIR__"cldating",
		"south"  : __DIR__"clforest4",
        ]));

	set("item_desc",([
	    "bian" : 
"    ��������������������������������������\n"
"    ��������������������������������������\n"
"    �������������������֡��������������\n"
"    ��������������������������������������\n"
"    ��������������������������������������\n",
            "bei" :
"    ���֣��ݴ�����������ʫ����Ī�ǳ������ִ����������������ɡ���\n"
"    ���ְ�ԭ�ǽ����ϲ�������С��ӵ��ߴ�����ʱ����ʼ����ȵ��\n"
"    �����԰������ܹ����£���Ϊ�����ã�ʨ���ã������ã������úͱ�\n"
"    ���ã���ֶ���Ǳ鲼���أ��������ơ����ְ�����������а������\n"
"    ��ɢ���ڰ����������޲��������֡������о�С����ҥ�ƣ������޳���\n"
"    �޳����֡�\n",
	]));

	set("cost", 1);
        set("objects",([
                __DIR__"npc/cl_qiu" : 1,
            ]));

        set("outdoors", "city");

        setup();
        // replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object ob;

        if( dir != "enter" )
                return ::valid_leave(me, dir);

        if( !(ob = present("qiu", environment(me))) )
                return ::valid_leave(me, dir);

        if( !living(ob) )
                return ::valid_leave(me, dir);

        if( me->query_temp("bangs/fam") == "���ְ�"
        ||  me->query("fam") == "���ְ�" )
                return ::valid_leave(me, dir);

        if( me->query_temp("changle/enter") ) {
                return ::valid_leave(me, dir);
        }

        message_vision("$N����$n��ǰ����ȵ����������ڰ��£�Ҫ�����Ŵ��š���ȥ��ƿ�Ϻõ�Ů������Т�����ӣ�\n", ob, me);
        return notify_fail("");
}