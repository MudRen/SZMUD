//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",  @LONG
�����Ͻ��ǵ�һ��ƫ�ţ��������Կ���������������������ſ�
�м������־���վ�ڣ�����ϸһ�������������ڴ��
LONG
	);

	set("exits", ([
		"east" : __DIR__"wuyingmen",	
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}