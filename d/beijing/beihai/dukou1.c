//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "�ɿ�");
	set("long", @LONG
������һ���ɿڣ�ר�Ÿ���ڶ��ο�ȥ�����ĵ����ġ��ɿ����ý�ʵ
��ľ�Ͻ���ģ���������һ����ӡ��ɴ�Ҳ�Ǻ��µ�˫���δ�������������
�����ġ��������ҷֱ����ڴ�ͷ�ܴ�β����ʱ׼�������ˡ�
LONG
	);
	set("cost", 2);
    
	set("exits", ([
                "southwest" : __DIR__"xiaolu2",
                "northeast" : __DIR__"xitian",
                "north" : __DIR__"jiulongbi",
        ]));
	
	
	setup();
	replace_program(ROOM);
}