// Code of ShenZhou
// Room: mjroom place to play mj 
// Mantian 05/12/2001

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", GRN"�齫��"NOR);
	set("long", @LONG
¹����������Խ��Խ���¿��ŵ��齫��������źܶ��ˡ���ȻΤС���Լ�
���ֲ�ʶһ�ᣬȴҲ��ӹ���ŵ�������ǽ��д��һ�ι�ѵ������ֶ��ƣ�������
Ʒ��Ʒ���򾲣��������ʣ����𽾣�ʧ���ߣ�˳ʱ��ϲ����ʱ��������ɫ��
�����������뺭���Ʒ��Ϊ�󣬶������ģ�˹Ϊ�ϳˡ���������°�(Board)
����������ڴ��ĵط���
LONG);
	set("exits", ([
		"south" : __DIR__"mjroom1",
		"west" : __DIR__"mjroom2",
		"north" : __DIR__"mjroom3",
		"east" : __DIR__"mjroom4",
		"down" : __DIR__"xiaobaozhai",
		]));
	set("no_fight", 1);
	set("no_sleep_room", 1);
	set("no_clean_up", 0);
	set("cost", 3);
	setup();
}
void init()
{
    add_action("do_look", "look");
    add_action("do_look", "l");
}

int do_look(string arg)
{
	object env1, env2, env3, env4;
    object *obj1, *obj2, *obj3, *obj4;
    object me = this_player();
	string msg;
    int i, i1, i2, i3, i4;

	if (!arg || arg != "board") return 0;

	env1 = load_object(__DIR__"mjroom1.c");
	obj1 = all_inventory(env1);

	env2 = load_object(__DIR__"mjroom2.c");
	obj2 = all_inventory(env2);

	env3 = load_object(__DIR__"mjroom3.c");
	obj3 = all_inventory(env3);

	env4 = load_object(__DIR__"mjroom4.c");
	obj4 = all_inventory(env4);

	msg ="";
	if (env1->query_temp("mjstart")  ==  1) msg += RED"��ľͤ"NOR"���ƾ����ڽ����С�\n";
	if (env2->query_temp("mjstart")  ==  1) msg += YEL"�ƾ�Է"NOR"���ƾ����ڽ����С�\n";
	if (env3->query_temp("mjstart")  ==  1) msg += HIC"�����"NOR"���ƾ����ڽ����С�\n";
	if (env4->query_temp("mjstart")  ==  1) msg += GRN"�����"NOR"���ƾ����ڽ����С�\n";

	for (i = 0; i < sizeof(obj1); i++) 
        if (userp(obj1[i]))
            i1++;

    for (i = 0; i < sizeof(obj2); i++) 
        if (userp(obj2[i]))
            i2++;

    for (i = 0; i < sizeof(obj3); i++) 
        if (userp(obj3[i]))
            i3++;

    for (i = 0; i < sizeof(obj4); i++) 
        if (userp(obj4[i]))
            i4++;

        tell_object(me, "���ڸ��齫����������У�\n"+ 
		"��������"HIC"�����\n"+
		"����������"+i3+NOR"\n"+
		YEL" �ƾ�Է "+i2+NOR"����"GRN+i4+" �����\n"NOR+ 
		"����������"RED+i1+"\n"+
		"����������ľͤ\n\n"NOR+msg);
    return 1;
}
int valid_leave(object me, string dir)
{
	object room;
	mapping exit;

	exit = environment(me)->query("exits");

	if ( dir == "east" || dir == "north" || dir == "west" || dir == "south" )
	{
		if( !( room = find_object(exit[dir])) )
			room = load_object(exit[dir]);
		if( room->query_temp("mjstart")  ==  1 )
			return notify_fail("�Ǽ��齫�ҵ��ƾ����ڽ����У������ֽ����ٽ�ȥ��\n");
	}
	return ::valid_leave(me, dir);
}
