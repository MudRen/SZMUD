// Code of ShenZhou
// /kungfu/skill/zuoyou-hubo.c
// by sdong 07/98

inherit SKILL;

int valid_learn()
{
	object me = this_player();

		if( me->query("gender") == "女性")
		{
			return 1;
		}
		
		return notify_fail("你不是女性所以不能学\n");

}
