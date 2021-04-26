// Code of ShenZhou
//��Է
//From:http://www.lhmz.yn.cninfo.net/jackyboy/default.htm
//Modified by xQin 4/00
//xQin 8/00 

#include <ansi.h>
inherit  ROOM;

string look_zi();

void  create  ()
{
    set  ("short", "��ԯ��Է");
    set  ("long",@LONG
�������¿��ŵ���ԯ��Է��ֻ��Է�ڲ��ü�ȴҲʮ�����š�����������ʿ
��ϲ�����˶���̸�졣Է�ڻ����������������ң���ϲ�������ŵĿ��˿��Խ�ȥ
���������塣��̨�����һ����(zi)��   
LONG);

    set("item_desc", ([
    "zi" : 
"��Χ��ʮ��֮һ��������̰ʤ \n"
"��Χ��ʮ��֮����������˻� \n"
"��Χ��ʮ��֮���������˹��� \n"
"��Χ��ʮ��֮�ġ����������� \n"
"��Χ��ʮ��֮�塿����С�ʹ� \n"
"��Χ��ʮ��֮��������Σ���� \n"
"��Χ��ʮ��֮�ߡ����������� \n"
"��Χ��ʮ��֮�ˡ���������Ӧ \n"
"��Χ��ʮ��֮�š�����ǿ�Ա� \n"
"��Χ��ʮ��֮ʮ�����ƹ�ȡ�� \n",

    ]));

    set("exits",  ([
    "west"  : "/d/city/wqiyuan1",
    "east"  : "/d/city/wqiyuan2",
    "south" : "/d/city/wqiyuan3",
    "north"  : "/d/city/xidajie1",
    ]));

    setup();
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
