// Code of ShenZhou
// �ź�ͤ
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", RED"�ź�ͤ"NOR);
    set("long", @LONG
ͤ����������÷����һ����ĩ������÷��ʢ�ţ�εȻ�ɹۡ���ͤ
��Ϊ�˼��������ʫ���ֺ;����������ᰮ÷��������Ӱ��бˮ��
ǳ�����㸡���»ƻ衱��������ӽ÷���䡣�ݴ�˵��ʫ�˻�����һֻ��
ȡ������������ÿ���Լ����ɢ����ǡ�п�������ʱ��ͯ�ӾͿ�����
�ף�ʫ�˼��ף���ؼҽӿͣ��������С�÷�޺��ӡ��Ĺ��¡�������
�߱���ƽ�����¡����ϱ����ǹ�ɽ��
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
	"southeast" : __DIR__"pinghu", 
	"southwest" : __DIR__"gushan1", 
                ])
       );
	set("cost", 1);
    setup();
    replace_program(ROOM);

}
