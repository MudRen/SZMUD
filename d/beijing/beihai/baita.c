//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����Ϊ������Ϊ������ɵ����澰�۵����ġ�λ�ڱ�������֮�ۡ�����
��Ϊ����������Ϊ�ߴ��שʯ̨��������Ϊ�۽�ʽ�����������ϳ��и���ʽ����
�������к���ʽ�۹��ţ����ڿ��в�����������ϲ�Ϊϸ����ʮ���죬��Ϊ��
��ͭ��ɡ�ǣ���Ե��ͭ��ʮ�ĸ�������Ϊ�̽���汦����ɲ��
LONG
	);
	set("cost", 2);
	
      
	 
	set("exits", ([
                "northdown" : __DIR__"yilan",
                "southdown" : __DIR__"yongansi",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
