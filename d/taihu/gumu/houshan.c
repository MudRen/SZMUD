// Code of ShenZhou
//GU MU FROM SANTA
//houshan.C

inherit ROOM;

void create()
{
	set("short", "����ɽ������ɽ");
	set("long", @LONG
����������ɽ�ĺ�ɽ��ǰ����һƬï�ܵ����֣�����ں����ġ�
��������һ��ʯ����shibei)��  
LONG
	);
	set("item_desc", ([
	"shibei" : "\n
		
		��	ȫ
		
		��	��
	��	
	��	��	��
	��
	��	��	��
		        \n",
	]));


	set("exits", ([
		"enter" : __DIR__"shulin1",
		"south" : __DIR__"shan"
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}



