// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��ˮ��");
	set("long", @LONG
һ�������ಽ����ʯ�š����ź���ˮ�������¹سǺʹ���ǣ�
�����峺�Ķ�ˮ������ȥ���ű������¹سǵĳ��ţ�����һ·����ʮ
���Ｔ�ɵ�����ǡ�
LONG
        );

	set("exits", ([
		"north" : __DIR__"xiaguan",
		"southeast" : __DIR__"gaten1",
		]));

	set("outdoors","dali");
       set("fjing", 1);
	set("cost", 2);
	setup();
}
