//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǳй��ľ����ã���ʮ��䣬Ե��ǽ�ɻ���֮�ơ��ٴ�������
����һ����������ķ�⡣��������ķ��ż���̴ľ���ӡ��м���һ�Ű�
��������Ȼ����������������ȴ��Ȼ����ɨ��һ����Ⱦ��
LONG
	);
	set("cost", 2);
        
	 
	set("exits", ([
                "south" : __DIR__"chengguang",
        ]));
	
	
	setup();
	replace_program(ROOM);
}

