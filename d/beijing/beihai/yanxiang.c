//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�ų�Ϊһ��̨��Բ�Σ�̨��4.6�ף��ܳ�276�ס���֮��Ҵ���ţ���Ի�Ѿ���
��Ի���飬�����еŵ�����������ųǵ������š��ſ��м�������ɨ�ء�
LONG
	);
	set("cost", 2);
        
	 
	set("exits", ([
                "west" : __DIR__"ximen",
                "east" : __DIR__"chengguang",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
