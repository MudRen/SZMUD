//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",  @LONG
����̫�͵�ǰ�㳡��һ�����ţ�ͨ����Ӣ���������������
�ţ�������һ��С����
LONG
	);

	set("exits", ([
        "west" : __DIR__"gzxd1",
        "east" : __DIR__"guang1",
        "south" : __DIR__"zhendumen",
        "northwest" : __DIR__"hongyige",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
