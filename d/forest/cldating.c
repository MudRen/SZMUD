// Code of ShenZhou
// /d/huanghe/changle/dating.c
// by aln  2 / 98

#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "����");
        set("long",
"������һ����ɱ����֮�������ü�Ϊ�����������ʮ��֮�ڡ�\n"
"ֻ���������ϵ������λεľ������п���һ�Ż�Ƥ���Ρ���ʱ�а�\n"
"�ھ������������Ϣ�����ص�ͷ�߹�������ʯ��������һ�����ӣ�\n"
"�����ʲݵ�д�ţ�"HIW"���ܹ��������������������������в��������\n"NOR 
HIW"�����������Ե�Ƭ�̱�ɵõ���һ�ι�����"NOR"��������Ҳ����û�취��\n"
"��ʲô�¶������ϵ�ù�ɡ�:(\n\n");

        set("exits", ([
		"out" : __DIR__"cldamen",
		"north" : __DIR__"clzoulang1",
        ]));
        set("no_fight","�ڳ��ְ�ĵ����ϻ��Ǳ�̫�����ĺá�\n");

        set("cost", 1);

        set("objects",([
                __DIR__"npc/cl_bei" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
