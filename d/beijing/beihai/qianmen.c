//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "ǰ��");
	set("long", @LONG
�����Ǳ�����ǰ�ţ����ڱ�����ר�Ź��ʹ��������ֵĵط�������һ����
��������ͨ�ϰ����ǲ����Խ�ȥ�ġ��������ɫ�ģ�����Ϲ���һ����(bian)��
�ſ�վ��������ʿ��
LONG
	);
	set("cost", 2);
	set("item_desc", ([
	"bian" : "����һ���ɫ���ң������ý���д���ĸ�����:���� ��Է\n",
		  
        ]));
	set("exits", ([
                "east" : __DIR__"shulin",
                "southwest" : __DIR__"zhaojing",
        ]));

	setup();
	replace_program(ROOM);
}
