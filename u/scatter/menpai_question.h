//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//********************   Menpai QUESTION Star Here   **************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************

void menpai_question(object me, string strName, string strId, string strFName, int intExp)
{
        object npc;
        string strMsg, answer, qn;
        int r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16;
        r1 = random(5) + 5;
        r2 = random(5) + 10;
        r3 = random(5) + 15;
        r4 = random(5) + 20;
        r5 = random(5) + 25;
        r6 = random(5) + 30;
        r7 = random(5) + 35;
        r8 = random(5) + 40;
        r9 = random(5) + 45;
        r10 = random(5) + 50;
        r11 = random(5) + 55;
        r12 = random(5) + 60;
        r13 = random(5) + 65;
        r14 = random(5) + 70;
        r15 = random(5) + 75;
        r16 = random(5) + 80;


        switch(random(25))
        {
        case 0:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r1+" * "+r2+" * "+r3+" * "+r4+" * "+r5+" *\n";
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r6+" *  1 *  4 *  7 * "+r16+" *\n";
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r7+" *  2 *  5 *  8 * "+r15+" *\n";
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r8+" *  3 *  6 *  9 * "+r14+" *\n";
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r9+" * "+r10+" * "+r11+" * "+r12+" * "+r3+" *\n";
                        strMsg = strMsg + "**************************\n";

                        answer = "2t"+r10+" "+r10+"t"+r16+" "+r16+"t1 1t9";

                        tell_object(me, strMsg);
                        tell_object(me, HIW"������ĳ���ɵ����Σ����Ҫ�ƽ�������������ڽ�һ����ȫ������\nһ����������Ͳ��������ˣ�������ʮ���ʱ��˼��"NOR);
                        tell_object(me, NOR"\n�ش𷽷�ʹ�õ�Ե㷽ʽ�������һ������Ȼ����������Ȼ�������������ߵ�һ��ָ��Ϊ ans 1t3 3t9 9t7 7t1��\n"NOR);
                        tell_object(me, NOR"��������ش� (��ʼֱ�� 2)\n"NOR);
                        qn="G1";
                        break;
                }
        case 1:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "һ�򣬶��ɣ����������飬��ƽ����ˣ�����÷����ĺ����ѣ���񳤴���ˣ�\n";
                        strMsg = strMsg + "���Ե���������ϰ壬��ʦ������ϰ壬�ξƾ����̺͹�˾ְԱ��\n\n";
                        strMsg = strMsg + "1.������ϰ岻��������Ҳ�������顣\n";
                        strMsg = strMsg + "2.�ξƾ����̲������飬Ҳ����һ��\n";
                        strMsg = strMsg + "3.���⣬��������ƽס��ͬһ����Ԣ�������ǹ�˾ְԱ�ļҡ�\n";
                        strMsg = strMsg + "4.����Ȣ��ʦ��Ů��ʱ�����������ǵ�ý�ˡ�\n";
                        strMsg = strMsg + "5.һ��������п�ʱ���ͺ�����ϰ壬������ϰ���ơ�\n";
                        strMsg = strMsg + "6.���ң�ÿ��ʮ�죬�������ƽһ��Ҫ�������޸�����\n";
                        strMsg = strMsg + "7.���ǣ���˾ְԱ��һ���Լ��κ��ӣ�������������ȥ��\n\n";
                        strMsg = strMsg + "���� : �뽫������˵�ְҵ����˳��д�������ÿո����ֿ�\n";
                        strMsg = strMsg + "(ʹ�� ans <һ���ְҵ> <���ɵ�ְҵ> <������ְҵ> <�����ְҵ> <��ƽ��ְҵ>\n";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        answer = "��ʦ ��˾ְԱ �ξƾ����� ����ϰ� ������ϰ�";
                        qn="L2";
                        break;
                }
        case 2:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "(4 * 2 / 4) * (4 * 2 / 4) + 4 - 4 * 2 = X\n";
                        strMsg = strMsg + "X + 3 + 7 - 4 / 2 - 8 = Y\n";
                        strMsg = strMsg + "0 * X + 3 * Y / 3 - 12 = Z\n";
                        strMsg = strMsg + "Z * 100 * Y / 100 / 5 * X + 100 - 149 + 49 + Z + 100 = K\n";
                        strMsg = strMsg + "\n�������� : K ����ֵ�Ƕ���?\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "88";
                        qn="M3";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }
        case 4:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "(4 * 2 / 4) * (4 * 2 / 4) + 4 - 4 * 2 = X\n";
                        strMsg = strMsg + "X + 3 + 7 - 4 / 2 - 8 = Y\n";
                        strMsg = strMsg + "0 * X + 3 * Y / 3 - 12 = Z\n";
                        strMsg = strMsg + "1 + Z * 100 * Y / 100 / 5 * X + 100 - 149 + 49 + Z + 12 + 100 = K\n";
                        strMsg = strMsg + "\n�������� : K ����ֵ�Ƕ���?\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "101";
                        qn="M4";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }

        case 5:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + " ****1**** \n";
                        strMsg = strMsg + " *       * \n";
                        strMsg = strMsg + " 2       3 \n";
                        strMsg = strMsg + " *       * \n";
                        strMsg = strMsg + " ****4*******8**** \n";
                        strMsg = strMsg + " *       *       * \n";
                        strMsg = strMsg + " 5       6       9 \n";
                        strMsg = strMsg + " *       *       * \n";
                        strMsg = strMsg + " ****7******10**** \n\n";
                        strMsg = strMsg + "������ĳ�����书�Ĺ���������ת������ļ���ͼ��\n";
                        strMsg = strMsg + "\n���� : Ҫ�ƶ������߲ſ��Բ����ĸ�ͬ���ĳ�����?\n";
                        strMsg = strMsg + "ʹ�� ans <����һ> <���ֶ�>    ע��: ���������С�ŵ����\n";
                        
                        answer = "5 7";
                        qn="G5";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }

        case 6:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "         ****1**** \n";
                        strMsg = strMsg + "         *       * \n";
                        strMsg = strMsg + "         3       6 \n";
                        strMsg = strMsg + "         *       * \n";
                        strMsg = strMsg + " ****2****       * \n";
                        strMsg = strMsg + " *       *       * \n";
                        strMsg = strMsg + "12      13       16\n";
                        strMsg = strMsg + " *       *       * \n";
                        strMsg = strMsg + " *       ****5*******8***** \n";
                        strMsg = strMsg + " *       *                *\n";
                        strMsg = strMsg + "14       7                9\n";
                        strMsg = strMsg + " *       *                *\n";
                        strMsg = strMsg + " ***15******10******11*****\n";
                        strMsg = strMsg + "������ĳ�����书�ķ���������ת������ļ���ͼ��\n";
                        strMsg = strMsg + "\n���� : Ҫ�ƶ������߲ſ��Բ�������������?\n";
                        strMsg = strMsg + "ʹ�� ans <����һ> <���ֶ�> <������>    ע��: ���������С�ŵ����\n";
                        answer = "8 9 11";
                        qn="G6";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }

        case 7:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "****1****\n";
                        strMsg = strMsg + "*       *\n";
                        strMsg = strMsg + "2       3\n";
                        strMsg = strMsg + "*       *\n";
                        strMsg = strMsg + "****4****\n";
                        strMsg = strMsg + "*       *\n";
                        strMsg = strMsg + "5       6\n";
                        strMsg = strMsg + "*       *\n";
                        strMsg = strMsg + "****7*******8*******9****\n";
                        strMsg = strMsg + "*       *       *       *\n";
                        strMsg = strMsg + "10      11      12      13\n";
                        strMsg = strMsg + "*       *       *       * \n";
                        strMsg = strMsg + "***14******15******16**** \n";
                        strMsg = strMsg + "������ĳ�����书�Ľ�����ת������ļ���ͼ��\n";
                        strMsg = strMsg + "\n���� : Ҫ�ƶ����ı߲ſ��Բ����ĸ�һ�����������?\n";
                        strMsg = strMsg + "ʹ�� ans <����һ> <���ֶ�> <������> <������>    ע��: ���������С�ŵ����\n";
                        answer = "5 6 8 15";
                        qn="G7";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }


        case 8:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "****1*******2*******3****\n";
                        strMsg = strMsg + "*       *       *       *\n";
                        strMsg = strMsg + "4       5       6       7\n";
                        strMsg = strMsg + "*       *       *       *\n";
                        strMsg = strMsg + "****8*******9******10****\n";
                        strMsg = strMsg + "*       *       *       *\n";
                        strMsg = strMsg + "11      12      13      14\n";
                        strMsg = strMsg + "*       *       *       *\n";
                        strMsg = strMsg + "***15******16******17****\n";
                        strMsg = strMsg + "*       *       *       *\n";
                        strMsg = strMsg + "18      19      20      21\n";
                        strMsg = strMsg + "*       *       *       *\n";
                        strMsg = strMsg + "***22******23******24****\n";
                        strMsg = strMsg + "������ĳ�����书���Ʒ���ת������ļ���ͼ��\n";
                        strMsg = strMsg + "\n���� : Ҫ�ƶ����ı߲ſ��Բ������һ�����������?\n";
                        strMsg = strMsg + "ʹ�� ans <����һ> <���ֶ�> <������> <������>    ע��: ���������С�ŵ����\n";
                        answer = "2 11 14 23";
                        qn="G8";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }

		case 9:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : ��Ӱ��̩̹��˺š�(TITANIC)�������������ʲô���г����ģ�\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "ŦԼ";
                        qn="k9";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }

		case 10:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : �������������ˡ������ǽ�ʲô���֣�\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "�ϲ�";
                        qn="k10";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }

		case 11:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : ͨ������ָ��FR��ָʲô���͵�������\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "ǰ�������������";
                        qn="k11";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }
		case 12:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : ͨ������ָ��MR��ָʲô���͵�������\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "���������������";
                        qn="k12";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }
		case 13:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : ͨ������ָ��4WD��ָʲô���͵�����ϵͳ��\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "��������";
                        qn="k13";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }
		case 14:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : ͨ����ָ�������ж��ٸ�����ָʲô���ס���\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "����";
                        qn="k14";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }
		case 15:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ͨ��������������ͨ���ж��ٸ�����ѹ��ѹ����\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "1";
                        qn="k15";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }

		case 16:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : �����ϵ�һ������ͼ��MUD��ʲô��\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "���紴����";
                        qn="k16";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }
		case 17:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : ������������ơ���������˭��\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "���ٳ�";
                        qn="k17";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }

		case 18:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : ����������������ʲô��\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "����";
                        qn="k18";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }
		case 19:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : ��������˭��\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "����";
                        qn="k19";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }
		case 20:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : �峯�������հ��¾��ޣ���ô����ʲô��\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "����";
                        qn="k20";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }

		case 21:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : ������䣬�����-�����һ��ʿ��ʲô����\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "����";
                        qn="k21";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }
		case 22:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : һ����ͨ�Ĺ���(CD)�ܴ�Ŷ��ٷ��ӵ����֣�\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "74";
                        qn="k22";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }
		case 23:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : ����ĩ������λ������������صġ���\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "������";
                        qn="k23";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
                }
		case 24:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "\n���� : �й��Ŵ�����ѧ˵���ƣ���̫�������ǡ���ô������ʲô�أ�\n";
                        strMsg = strMsg + "ʹ�� ans <��>\n";
                        answer = "����";
                        qn="k24";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"��������ش�\n"NOR);
                        break;
				}


        default:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r1+" * "+r2+" * "+r3+" * "+r4+" * "+r5+" *\n";
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r6+" *  1 *  4 *  7 * "+r16+" *\n";
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r7+" *  2 *  5 *  8 * "+r15+" *\n";
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r8+" *  3 *  6 *  9 * "+r14+" *\n";
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r9+" * "+r10+" * "+r11+" * "+r12+" * "+r3+" *\n";
                        strMsg = strMsg + "**************************\n";

                        answer = "2t"+r10+" "+r10+"t"+r16+" "+r16+"t1 1t9";

                        tell_object(me, strMsg);
                        tell_object(me, HIW"������ĳ���ɵ����Σ����Ҫ�ƽ�������������ڽ�һ����ȫ������\nһ����������Ͳ��������ˣ�������ʮ���ʱ��˼��"NOR);
                        tell_object(me, NOR"\n�ش𷽷�ʹ�õ�Ե㷽ʽ�������һ������Ȼ����������Ȼ�������������ߵ�һ��ָ��Ϊ ans 1t3 3t9 9t7 7t1��\n"NOR);
                        qn="G1";
                }
        }

        me->start_busy(3);
        npc = new("/family_job/ansnpc");
        npc->set("aid", me->query("id"));
        npc->move(environment(me));
        npc->set("correctans", answer);

        CHANNEL_D->do_channel(this_object(), "sys", sprintf("����Ŀ��: %s(%s)  ����NPC: %s  ������̬: �ǻ�������  ��Ŀ���: %s", me->query("name"), me->query("id"), npc->query("name"), qn));
        return;
}