//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",  @LONG
�����Ͻ��ǵ�һ��ƫ�ţ��������Կ���������������������ſ�
�м���������վ�ڣ�����ϸһ�������������ڴ��������ʱ����һ
������˻��
LONG
	);

	set("exits", ([
		"west" : __DIR__"wenhuamen",	
//		"east" : "/d/beijing/east/wangfudajie2",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
