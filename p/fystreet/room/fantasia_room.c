//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 801
inherit ROOM;
void create()
{	set("short","[1;36m流星花园（MeteorGarden)[37;0m");
	set("long",@LONGLONGAGO
温柔的星空　应该让你感动　我再你身旁　为你布置一片天空 
不准你难过　替你摆平寂寞　梦想的重量　全部都交给我
牵你手　跟着我走　风再大又怎样　你有了我　再也不会迷路方向 
伤感若太多　心丢给我保护　疲倦的烟火　我都会替你赶走
灿烂的言语　只能点缀情感　如果我沉默　因为我真的爱你 
牵你手　跟着我走　风再大又怎样　你有了我　再也不会迷路方向
雨和云渐渐散开　洒下一片温暖　我要分享你眼中的泪光 
陪你去看 流星雨 落在这地球上　让你的泪落在我肩膀
要你相信我的爱只肯为你勇敢　你会看见幸福的所在
P.S. This House is For the Specialest Woman in My Heart
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","fantasia");
       set("no_fight",1);
       set("no_magic",1);
       set("sleep_room",1);
       set("if_bed",1);
       set("NONPC",1);
       set("no_dazuo",1);
       set("no_study",1);
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	set("objects", ([__DIR__"obj/cabinet" : 1,]),);
	setup();
   call_other("/p/fystreet/board/fantasia_board","???");
}
#include "indoor_func.c"
