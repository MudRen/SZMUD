// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǵ�Խ��ɽ����Ҫ���ڡ�С·�������ۣ�ɽ�ƶ��ͣ�ɽȪ��
�۳�Ϫ����ʱ����Ϊ�ٲ���һ·��ɽ��ˮ�㣬��ɫ���ˡ��Ӱ�������
����ʮ���ׯ��������İ�ݺᡣ
LONG
	);
	set("exits", ([
                "north" : __DIR__"alagou2",
                "southdown" : __DIR__"shankou",
        ]));
	set("cost", 3);
     set("fjing", 1);
	set("resource/water",1);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
