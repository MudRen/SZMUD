//Cracked by Roath
inherit ROOM;

void create()
{
    set("short", "���ȵ�");
	set("long",  @LONG
���ǻʼҹ������ڵĵط��������������ƣ����е������ϰڷ���
�ʼ��������ڵ���λ��
LONG
	);

	set("exits", ([
        "south" : __DIR__"guang4",
	]));
	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
