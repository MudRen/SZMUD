//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
���������������ϣ����������ƻ����š�������ȯ���������Σ���������ʯ���¶�
ƽ�������������е�̾�������������������ϱ��ֱ�����������¥ʽľ�Ʒ�һ����
��Ͳ�߶������ɫԲ����ɫ�����޶�Ŀ��
LONG
	);
	set("cost", 2);
	
      
	 
	set("exits", ([
                "north" : __DIR__"yongansi",
                "south" : __DIR__"zhaojing",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
