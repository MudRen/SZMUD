//Cracked by Roath
inherit ROOM;

void create()
{
    set("short", "���ʸ�");
	set("long",  @LONG
 �����ż�,��������,Ժ��ʽ�ݶ�,����������Ľ���,�念��ʱ,
 ���ٲ�ѧ���������ڴ�.��Ϊ��͢�ⷿ.
LONG
	);

	set("exits",  ([
        "westdown" : __DIR__"guang1",
	]));
	
	setup();
	replace_program(ROOM);
}
