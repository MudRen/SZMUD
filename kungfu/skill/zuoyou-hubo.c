// Code of ShenZhou
// /kungfu/skill/zuoyou-hubo.c
// by sdong 07/98

inherit SKILL;

int valid_learn()
{
	object me = this_player();

		if( me->query("gender") == "Ů��")
		{
			return 1;
		}
		
		return notify_fail("�㲻��Ů�����Բ���ѧ\n");

}
