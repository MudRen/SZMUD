//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long",  @LONG
�����ǹ�͢�ⷿ�������ż䣬�������䣬Ժ��ʽ�ݶ����������
����Ľ�����
LONG
	);

	set("exits",  ([
        "southeast" : __DIR__"youyimen",
	]));
	
	setup();
	replace_program(ROOM);
}
