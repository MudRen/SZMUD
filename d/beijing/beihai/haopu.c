//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "�姼�");
	set("long", @LONG
����֮�姽���Ϊ����ˮ鿡����ڻ���ի�������е��������ɽʯ���ơ�
�����ɽʯ����һ����ˮ�������г��������š������仯�����֮�ڣ��ľ�
��Ȼ֮Ȥ��
LONG
	);
	set("cost", 2);
	set("exits", ([
                "northwest" : __DIR__"huafang",
             ]));
	
	
	setup();
	replace_program(ROOM);
}
