//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǳ��������ţ�ľ�Ƶ��ſ�����˴��ɫ����Ȼ�������ڵ�����
������ɫȴ�Ծ�ʮ�����ޡ����ĳ�������ר��ά���ġ�����û�������ı�־��
���ſ�վ�ż�����ʿ�����졣����ԶԶ���Կ����ų���Ʈ������ġ�
LONG
	);
	set("cost", 2);
	
	set("exits", ([
                "north" : __DIR__"xiaolu1",
                "west" : "/d/beijing/beihai",
                "east" : __DIR__"yanxiang",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
