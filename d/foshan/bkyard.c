// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

int do_jiaofen(string);

void create()
{
        set("short", "�ݼҺ�Ժ");
        set("long", @LONG
�����Ǹ�С��԰��Ժ�����˺ö��߲ˡ���԰�ӵ�һ���и����(chi)��
����Ʈ��Щ����ζ����
LONG
        );
        set("exits", ([
		"east" : __DIR__"yard",
	]));
	set("item_desc", ([
		"chi" : "������и����ף�������������(jiaofen)��\n",
	]));
	set("objects", ([
		__DIR__"obj/kongxin" : 2,
		"/d/wudang/npc/bee" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
}

void init()
{
        add_action("do_jiaofen","jiaofen");
}

int do_jiaofen(string arg)
{
        object me;
        me = this_player();

	me->receive_damage("qi",10, "��ũ��������");
	me->add_temp("qi/work",1);
	message_vision("$Nһ����һ�׵ؽ��࣬�۵��������ۡ�\n", me);
	if (me->query("qi")<40)
		tell_object(me, "���Ѿ��۵�ֱ�������ˡ�\n", me);
	return 1;
}

