#include <room.h>
#include <ansi.h>
//Cracked by smzz
// xiulianshi.c ɳ������
 // by Xiang 

inherit ROOM;

void create()
{
set("short", HIM"ɳ�Ҵ���"NOR);
set("long",
"������ɳ�����������ͷ����һ���ǳ���ĵ��ƣ������������յ�ͨ��\n"
"�����������䣬����ȥ���﷽����ʲô���ܻ��ȥ�����,Ҫע�����Ŷ��\n"
"���ߺ�����ɳĮ֮�ӵ��鷿�ɣ���������кö���飮�������ǲ��ܴ��ߵ�\n"
"�������ɳĮ֮�ӵİ칫�ң���һ̧ͷ�Ϳ��Կ���ǽ�ϵ����й���һ���Ҷ�\n" 
"��һ��������"HIW"������"NOR"(door)�����ǿ������˾��ø�ֺܺ���\n"
" "BLINK+MAG"------------------\n"NOR
""MAG"|"NOR+BLINK+HIW"ɳĮ��� �Ѱ����� "NOR+MAG"|\n"NOR
" "BLINK+MAG"------------------\n"NOR
);
set("exits", ([ "out":"/u/smzz/workroom",
"north":__DIR__"shufang",
"east":"u/smzz/wsj",
"up":__DIR__"louti1",
]));     set("objects", ([ 
          "u/smzz/coffee.c" : 1,
          "u/smzz/ojuice.c" : 1 ]));
set("cost", 1);
set("item_desc",
([
"door":"����һ���й�����������ɲ�����,�������ܽ�ʵ�����open����\n"
]));
set("invalid_startroom", 1); 
set("cost", 3);
create_door("east", "ľ��", "west", DOOR_CLOSED); 
          setup();
          replace_program(ROOM);
}
