//Created by Zyu on k1-08-20

inherit ROOM;

void create()
{
    set("short", "车中");
    set("long", @LONG
车里干干净净，放了一张舒服的大椅子。窗帘拉了下来，阳光从缝隙
中透进来，不知道车子走到哪里了。门外挂了一串风铃，叮呤呤响着。车
夫坐在前面，一路赶着马，一路得意地哼着什么小调。

LONG
    );

       set("no_fight", 1);
	set("no_steal", 1);
	set("sleep_room", 0);
       setup();
}