// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "Ӣ�۵䵱");
        set("long", @LONG
������һ�Ÿ߸ߵĹ�̨����̨�������ŵ��̵ĳ�����
�����Ƿ���ү������ʮ��������û�����ֹ��£�����Ҳ�ͺܷ�
�ġ���̨�������������ӣ��ֱ�����Ÿ�ʽ����(weapon)��
���ߴ���(armor)��ҩ��(drug)�����(book)����������
ʽ����(misc)��
LONG
        );
		set("no_sleep_room", "1");
        set("exits", ([
		"north" : __DIR__"street4",
	]));

	set("objects", ([
		"/d/qilian/npc/chaofeng" : 1,
	]));
	set("cost",1);
	set("no_beg", 1);
	setup();
        replace_program(ROOM);
}
