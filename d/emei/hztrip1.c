// Code of ShenZhou
//Jay 9/30/96

inherit ROOM;

void create()
{
        set("short", "С����");
	set("long", @LONG
���Ƕ���ɽ�𶥻��������һƬС���֡�����û��·����������ϡ��Щ��
�����ƺ��������߹���������һ��С����
LONG);
	set("exits", ([
		"south" : __DIR__"hztrip2",
	]));
        set("item_desc", ([
                "chuang" : "�����Ǳ��ǻ����ֵ�����\n",
                "��" : "�����Ǳ��ǻ����ֵ�����\n",
	]));


        set("outdoors", "emei" );

	set("cost", 2);
	setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{

        object me = this_player();

        if (arg!="chuang") return 0;
	if (present("song qingshu",environment(me)))
		return notify_fail("������һ����ס����ȡ�\n");
        message_vision("$N���˲�ע�⣬�������\n", me);
        me->move(__DIR__"hz_west");
        message_vision("$N�ӻ�����������������\n", me);
        return 1;
}


