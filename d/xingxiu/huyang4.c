// huyang road
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "������");
	set("long", @LONG
��·�������������������һƬ����ľ������Խ��ïʢ����ȥ
·�Ͻ���������ԶԶ�ɼ�������ɳ�ѻ��ɵ�ɽ��
LONG
	);

	set("exits", ([
		"east" : __DIR__"huyang3",
                "west" : "/d/baituo/xiaolu",
                ]));
	set("outdoors","xingxiu");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

