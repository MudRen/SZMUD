//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
�����ǵ�֮���ϵ�һ��ʯͤ������Ԫ�����͡�������ͨ�徧Ө��͸��
Ϊһ����ī���̶������������֮����������֮��ʵ�ǲ��ɶ��
֮�ȴ��֪����������������ʲô�ġ�
LONG
	);
	set("cost", 2);
        
	 
	set("exits", ([
                "north" : __DIR__"chengguang",
        ]));
	
	
	setup();
	replace_program(ROOM);
}

