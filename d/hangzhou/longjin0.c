// Code of ShenZhou
// ����
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "����");
    set("long", @LONG
ֻ����(jing)ˮ���ɼ��׶��������쳣������ԭ������������˵
�˾��뺣��ͨ�����бض������������꣬���������������ն�����
��ʫ������ɽ��ˮ��ѣ������������̶�������Խ��в��ҡ����ϱ�
�ش�·��
LONG);
    set("resource/water",1);
    set("exits", ([ /* sizeof() == 2 */ 
                  "east" : __DIR__"longjin1", 
                  "south" : __DIR__"road62", 
                 ])
       );
    set("item_desc", 
    	   ([
             "jing" : 
	     "��ˮ�峺���ף����ײ���һЩ��״С���������С�ѡ�\n"
   	   ])
	);
	set("cost", 2);
        set("outdoors", "hangzhou");
    setup();

}
void init()
{
   add_action("do_stir","stir");
   add_action("do_stir","��");
}
int do_stir(string arg)
{   if( !arg || arg=="" ) return 0;
    if( arg == "jing" || arg == "��")
    {
	message_vision("$N����������ָ������ˮ��ֻ��ˮ���ϳ���һ���䶯��ˮ�ƣ�\n", this_player());
	message_vision("�������ڽ�����С�������ʧ�ˡ�$N�ܵ����˵���Ǿ��Ƿ�ˮ\n", this_player());
	message_vision("�ߣ�֪���𡣡�\n", this_player());
    }
    return 1;
}
