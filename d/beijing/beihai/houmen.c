//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǳ�����԰�ĺ��ţ����������ŵġ���ǰ��վ��������ʿ����
���߳���ïʢ��ֲ�һЩ�������Ŷ�����������������æµ��������
����һ���ٵ���
LONG
	);
	set("cost", 2);
	set("exits", ([
                "west" : __DIR__"jingqing",
                "south" : __DIR__"huafang",
                ]));
	
	
	setup();
	replace_program(ROOM);
}
