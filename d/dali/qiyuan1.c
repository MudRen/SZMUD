// Code of ShenZhou
//��Է
//From:http://www.lhmz.yn.cninfo.net/jackyboy/default.htm
//Modified by xQin 4/00

#include <ansi.h>
inherit  ROOM;

string look_string();

void  create  ()
{
    set  ("short",  "������Է");
    set  ("long",@LONG
��Է�����ĸ���䣬����̸���ܵĺõط���������ϱ���������
�������һ�����ң���ÿ�����ҵ����ⶼ�������������ֵ����ӣ�
�ڷ�������������ϻ�����һ������ָ��(help)��
LONG);

    set("item_desc", ([
    "help" : ( : look_string : ),
    ]));

    set("exits",  ([
    "west"  : "/d/dali/qiyuan2",
    "south"  : "/d/dali/qiyuan3",
    "north"  : "/d/dali/qiyuan4",
    "east" : "/d/dali/taihejie2",
    ]));

    setup();
}

string look_string()
{
	string  msg  =  "��ӭ����Է�����壡\n"  +
"
��������������Χ��������壬����������Ĳ��裺
һ�����Һö��֣�Ȼ��ֱ���  sit black  ��  sit white  ������
����ʹ�� new ��ʼһ���µ���֣�new [-5] [-b(numbers)] [-h(numbers)]
    ���� -5  �����������壬��ѡ��Ϊ��Χ�壻
      �� -b  ָ���������̵Ĵ�С��
         -h  ָ�����ӵ���Ŀ��
�������磺
����Χ�� new
    �þ���Χ�壺new -h9
    ʮ���ʮ��������壺new -5 -b15
����ʹ�� play ��������
    ���� play d4 �ȵȡ�
�ġ�ʹ�� refresh �ۿ����̡�
�塢ʹ�� leave �뿪���̡�
����ʹ�� pass �������䡣
�ߡ�ʹ�� undo ���塣Ŀǰֻ�ṩ������Ļ��幦�ܡ�

";
	return  msg;
}

int valid_leave(object me, string dir)
{
        object room;
        mapping exit;

        exit = environment(me)->query("exits");

        if ( dir == "east" || dir == "north" || dir == "west" ) {
                if( !( room = find_object(exit[dir])) )
                       room = load_object(exit[dir]);
	        if( room->query_temp("action")  ==  1 )
                       return notify_fail("�Ǽ������Ѿ����˿�ʼ�����ˣ��������\n");
                }

        return ::valid_leave(me, dir);
}
