//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "午门 ");
	set("long",  @LONG
午门是紫禁城的正门，门左右向前伸出呈凹形，俗称五凤楼。城
楼内设有宝座，东西侧有钟鼓明廊，每逢朝会或庆典等都要鸣钟击鼓，
出征将士凯旋归来，皇帝都亲自到午门正楼举行受俘礼。

这是一个较小的牌楼。每天午时文武百官云集在这里，等候当今
圣上的召见。两边各有一个偏殿，供百官休息用。两队银甲卫士手举
长枪，红缨配银甲，威风凛凛，杀气腾腾。
LONG
	);

	set("exits", ([
        "north" : __DIR__"guang2",
        "south" : __DIR__"duanmen",
	]));

	set("objects", ([
		 "/d/beijing/npc/shiwei1" : 4,
	]));

	set("outdoors","beijing");
	setup();
};

int valid_leave(object me, string dir)
{
        int i;
        if ((dir=="north") && me->query("class")!="officer" && (objectp(present("yideng shiwei", environment(me)))))
                return notify_fail("银甲侍卫上前挡住你，朗声说道：皇宫禁地，禁止闲杂人等出入！\n");
        return ::valid_leave(me, dir);
}
