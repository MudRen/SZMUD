//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 500
inherit ROOM;
void create()
{	set("short","[1;33m世贸中心大厦[37;0m");
	set("long",@LONGLONGAGO
世贸中心大厦由南北两座双子楼构成，楼高411米，110层。
是神州最高的建筑。第107层是瞭望厅，极目远眺，神州美景尽
收眼底。 大楼集商务、贸易、服务等行业于一身，神州各界名
流，工商业、金融业、IT业等精英均荟萃于此。 地下还有五层
为大型超市及停车场。 大厦前的广场就有地铁站出口，交通方
便。自纽约世贸中心被恐怖份子摧毁后，为防神州有本.拉登的
追随者，大楼加强了安检措施。大楼上空5公里范围内设为禁飞
区，四周隐蔽处共设有六处爱国者导弹发射架。
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","lock");
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
   call_other("/p/fystreet/board/lock_board","???");
}
#include "indoor_func.c"
