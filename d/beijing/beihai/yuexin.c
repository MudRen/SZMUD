//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "���ĵ�");
	set("long", @LONG
��������������֮���ĵ����Ϊ�忪�䡢��ɽ���߶��������������
����֮�������ڷǳ�������ֻ��ϡ������ɮ��ɨ����Ҷ����������ǰ�п�
������̨��������¥��������Ժ����һ��������֦Ҷï�ܡ����ڹ��ߺܰ���
���������Щʲô��
LONG
	);
	set("cost", 2);
	
    
	 
	set("exits", ([
                "east" : __DIR__"yongansi",
                "northup" : __DIR__"qingxiao",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
