// Code of ShenZhou
// Room: /d/snow/herbshop1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��������������ң��ӵ��Ϻ��Ļҳ����ó������������
�˳��룬�����ߵĵ��Ϸ���һ�����ͣ�����һ����������ǽ�ϣ���֪��
��������ʲ���ˣ������ǽ(wall)���ú�ɼľ���ģ�����������Ļ���
ǽ�������Ե���Щ��Ѱ����
LONG
	);
	set("no_clean_up", 0);

	set("exits", ([
		"east" : __DIR__"chuchang",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
void init()
{
	object me = this_player();

	if ( me->query("eat_wan") && me->query("mud_age") < me->query("eat_age")+86400)
	{
	tell_object(me, "���ѷ����裬Ӧ��һ�����ٴη��ã����������𣡣���\n");
	}

	if ( me->query("eat_wan") && me->query("mud_age") > me->query("eat_age")+86400)
	{
	tell_object(me, "��һ����δ�����裬�������𣡣���\n");
	me->add("max_jingli", -100);
	me->add("max_neili", -100);
	me->set("eat_age", me->query("mud_age"));
	}

}
