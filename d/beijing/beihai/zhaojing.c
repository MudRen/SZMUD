//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "�Ѿ���");
	set("long", @LONG
�ų�Ϊһ��̨��Բ�Σ�̨��4.6�ף��ܳ�276�ס���֮��Ҵ���ţ���Ի�Ѿ���
��Ի���飬�����еŵ�����������ųǵ��Ѿ��š��ſ��м�������ɨ�ء�
LONG
	);
	set("cost", 2);
        
	 
	set("exits", ([
                "west" : __DIR__"chengguang",
                "northeast" : __DIR__"qianmen",
                "north" : __DIR__"yonganqiao",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
