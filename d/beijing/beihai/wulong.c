//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
�����ǲ�����ǰ֮����ͤ��ͤ������ˮ�У���ͤ��Ϊ���Σ�ǰ����䲼�á�
��ͤ�����������·��϶��ͣ��������ͤΪ���ܣ�����ͤΪ���ܣ�����ӿ��
ͤ������ͤ��������ͬ����ͤ���������߶������߼��ߣ���������ʩС�����
�Ӳʻ���Ѥ����ʡ�
LONG
	);
	set("cost", 2);
	
	set("exits", ([
                "west" : __DIR__"xiaolu2",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
