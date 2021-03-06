// Code of ShenZhou
//zyz /12/13/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "世祖皇帝平云南碑");
        set("long", @LONG
城西三月街上，矗立着一块巨碑“元世祖平云南碑”。巨碑
面临洱海，背倚苍山，蔚为壮观。此碑立于元大德八年(一三零?
哪?)，碑文撰写者是
翰林程文海，歌颂已去世的元朝开国皇帝世祖忽必烈的“圣德神功”。于
是立了此碑，巨碑高四。四四米，宽一。六五米，用二石相接而成。碑文
共五十行，上石三十行，每行二十字，下石二十八行，每行二十五字。全
碑一千三百字左右，正书，碑额篆书“世祖皇帝平云南碑”八字。
LONG
        );

        set("outdoors", "dali");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

