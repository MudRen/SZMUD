//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "�찲�� ");
	set("long",  @LONG
����׳�۵��찲�ų�¥��������������ǿ�󣬽���������������
��������������ʹ�ߴ�����˷����찲�ű����������������������
ǰ�����ߴ������ʯʨ������չʾ�ŵ۹������ˡ�
LONG
	);

	set("exits",([
		"north" : __DIR__"duanmen",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}