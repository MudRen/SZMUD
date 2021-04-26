// Jiuer Aug 15, 2001
// /d/jueqing/shanlu2.c

inherit ROOM;

void create()
{
	set("short","半山腰");

	set("long",@LONG
走到这里，山路稍稍平缓了一些。你坐下来稍事休息。抬头望望西
边的崖壁，见山壁陡峭，根本就无路可寻。回想刚才下山的情形，不由
出了身冷汗。远望东边山脚下有两、三间民房，炊烟缭绕，想是早起的
农家正在准备早饭，你站起身来继续向前走去。
LONG);
	
	set("exits",([
		"southeast" : __DIR__"shanlu3",
		"northup" : __DIR__"shanlu1",]));
	
	set("outdoors","jueqing");
	setup();
	replace_program(ROOM);
}