//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",  @LONG
������ǰ�����ܹ���Ϣ�����ĵط�����ǽ����һͰ��ɳ�ӣ���һ
������һ�������ӣ���֪�Ǹ�ʲ���õġ���������һ�����ӣ������Ա�
�������Ϸ��ż�ֻϸ�ɲ豭��һ����ɰ�Ĳ����
LONG
	);

	set("exits", ([
		"north" : __DIR__"wenyuange",
		"south" : __DIR__"wenhuadian",
	]));

	setup();
	replace_program(ROOM);
}