//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǳ����Ķ��ţ�ľ�Ƶ��ſ�����˴��ɫ����Ȼ�������ڵ����紵��
��ɫȴ�Ծ�ʮ�����ޡ����ĳ�������ר��ά���ġ�����û�������ı�־�����ſ�
վ�ż�����ʿ�����졣
LONG
	);
	set("cost", 2);
	set("exits", ([
                "south" : __DIR__"shulin",
                "northeast" : __DIR__"huafang",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
