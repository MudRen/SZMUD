//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",  @LONG
����ѵ���±��ĵط�������ɢ���Ÿ��ָ����ı����������̹���
����ĺ�ʿ���Դ򣬴������ȥ���±��������ǳ�����ʵ��
LONG
	);

	set("exits", ([
        "west" : __DIR__"guang3",
	]));

	setup();
	replace_program(ROOM);
}
