#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIG"房管处"NOR);
	set("long",@LONG
这里是神州大街房管处，里面坐着一个凶巴巴的老太太，她掌管着神
州大街的地皮买卖，就连鲁班也得什么都听他的。根据科学研究，据说这
样可以提高住宅小区的安全指数。墙上贴了张布告(note)。
LONG	);
	set("exits",([
	"west" : __DIR__"street0", 
		]));
	set("objects",([
	__DIR__"npc/master":1,
		]));
	set("item_desc", (["note":@TEXT
                   建   房   须   知
    先向房管询问“我要建房”，然后带鲁班到想要的街道位置，
(build here)，输入自己想要的房名与外观，再签个字，就行了。
    在房子建好前，去家具店看看有什么好东西，定上四五件回来
装修用吧。在房子里装修(zhuangxiu)时就可以自己输入房子的全
部描述了，想是什么样就要什么样吧。
    当然，如果又觉得住的不舒服，东西太旧了，也可以在自己的
房子里来一次打砸扔(dazareng)，不过要重新装修的话可是要重新
买家具的，想好了！

                                       房管处
TEXT      
	]));
	set("coor/x",40);
	set("coor/y",20);
	set("coor/z",0);
	call_other("/clone/board/house_b", "???"); 
	setup();
}