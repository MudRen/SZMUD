// Code of ShenZhou
// changle/clhuayuan.c

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
�����԰�ǵ��͵Ľ��Ϸ�񣬾���ϸ�¡�԰�л�����û��ʲô����
Ʒ�֣�Ҳ�����涷��������һ��ʯ���̾͵�С·������鲼��̦������
ʪ��������һ����,�����ǳ��ְ�ĺ����صء�
LONG );

        set("exits", ([
		"north" : __DIR__"clhoutang",
		"south" : __DIR__"clbajiaoting",
		"west" : __DIR__"clzoulang2",
		"east" :  __DIR__"clyongdao",
        ]));

        set("cost", 0);

        setup();

        replace_program(ROOM);
}

