//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "�ɿ�");
	set("long", @LONG
������һ���ɿڣ�ר�Ÿ���ڶ��ο��뿪��ȥ������ġ��ɿ����ý�ʵ��
ľ�Ͻ���ģ���������һ����ӡ��ɴ�Ҳ�Ǻ��µ�˫���δ������������ȵ����ġ�
�������ҷֱ����ڴ�ͷ�ܴ�β����ʱ׼�������ˡ�
LONG
	);
	set("cost", 2);
  
	set("exits", ([
                "southwest" : __DIR__"yilan",
                ]));
	
	
	setup();
	replace_program(ROOM);
}