// Code of ShenZhou
// jiulao1.c ���϶���
// Shan: 96/06/22

inherit ROOM;

void do_yell(string);

void create()
{
        set("short", "���϶���");
        set("long", @LONG
���϶����ɷ����⡣��˵Զ��ʱ���о�λ����ס����������֪����
���ں��꣬���ں��ꡣ��ԯ�ʵ۷õ��ڴˣ���һ���ţ���Ի�������º�������
Ի�������ˡ�������Ǿ��϶������������������������˽�ȥ��ֻ��Щ��
վ�ڶ���̸Ц���У�yell����������������ʮ�ŵ��յ�ǧ���֣�һ·�򱱵���
��ʯ��
LONG
        );

        set("exits", ([
		"northeast" : __DIR__"dao96",
		"northwest" : __DIR__"lianhua",
		"enter" : __DIR__"jiulao2.c"
        ]));

        set("objects", ([
                "/d/emei/npc/monkey" : 3,
        ]));

	set("outdoors", "emei");

	set("cost", 2);
        setup();
//	replace_program(ROOM);
}

void init()
{
    add_action("do_yell", "yell");
}

int do_yell(string arg)
{
	object me = this_player();

	message_vision("$Nվ�ڶ��������У���" + arg + "��\n", me);
        message_vision("���ڴ���һ���������" + arg +
            "������" + arg + "������" + arg + "��������\n", me);

	if ( me->query("family/master_id") == "zhou zhiruo"   
        	&& (arg == "���º���" || arg == "���º�" )) {
		tell_room(environment(me),(string)me->query("name")+"������ȥ��ת�۾Ͳ����ˡ�\n", me);
		tell_object(me, "\n��Ȼ�и�����ס�㣬���˶�������������ںڰ�����ת��ת�����þͳ��˶���\n\n");
		me->move(__DIR__"jiulao_out");
	    	return 1;
	}

	return 1;
}
/*
int through_cave(object me)
{
	tell_room(environment(me),(string)me->query("name")+"������ȥ��ת�۾Ͳ����ˡ�\n", me);
	tell_object(me, "\n��Ȼ�и�����ס�㣬���˶�������������ںڰ�����ת��ת�����þͳ��˶���\n\n");
	me->move(__DIR__"jiulao_out");
    	return 1;
}
*///delete by lisser because literate bug.

