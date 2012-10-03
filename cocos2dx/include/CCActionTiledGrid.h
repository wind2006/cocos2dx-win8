/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org
Copyright (c) 2009      On-Core

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

// For licensing information relating to this distribution please see Third Party Notices file.

#ifndef __ACTION_CCTILEDGRID_ACTION_H__
#define __ACTION_CCTILEDGRID_ACTION_H__

#include "CCActionGrid.h"

namespace cocos2d 
{
	/** @brief CCShakyTiles3D action */
	class CC_DLL CCShakyTiles3D : public CCTiledGrid3DAction
	{
	public:
		/** initializes the action with a range, whether or not to shake Z vertices, a grid size, and duration */
		bool initWithRange(int nRange, bool bShakeZ, const ccGridSize& gridSize,
			ccTime duration);

		virtual CCObject* copyWithZone(CCZone* pZone);
		virtual void update(ccTime time);

	public:
		/** creates the action with a range, whether or not to shake Z vertices, a grid size, and duration */
		static CCShakyTiles3D* actionWithRange(int nRange, bool bShakeZ, const ccGridSize& gridSize,
			ccTime duration);

	protected:
		int m_nRandrange;
		bool m_bShakeZ;
	};

	/** @brief CCShatteredTiles3D action */
	class CC_DLL CCShatteredTiles3D : public CCTiledGrid3DAction
	{
	public:
		/** initializes the action with a range, whether or not to shatter Z vertices, a grid size and duration */
        bool initWithRange(int nRange, bool bShatterZ, const ccGridSize& gridSize,
			ccTime duration);

		virtual CCObject* copyWithZone(CCZone* pZone);
		virtual void update(ccTime time);

	public:
		/** creates the action with a range, whether of not to shatter Z vertices, a grid size and duration */
		static CCShatteredTiles3D* actionWithRange(int nRange, bool bShatterZ, const ccGridSize& gridSize,
			ccTime duration);

	protected:
		int m_nRandrange;
		bool m_bOnce;
		bool m_bShatterZ;
	};

	struct Tile;
	/** @brief CCShuffleTiles action
	 Shuffle the tiles in random order
	 */
	class CC_DLL CCShuffleTiles : public CCTiledGrid3DAction
	{
	public:
		~CCShuffleTiles(void);
		/** initializes the action with a random seed, the grid size and the duration */
		bool initWithSeed(int s, const ccGridSize& gridSize, ccTime duration);
		void shuffle(int *pArray, unsigned int nLen);
		ccGridSize getDelta(const ccGridSize& pos);
		void placeTile(const ccGridSize& pos, Tile *t);

		virtual void startWithTarget(CCNode *pTarget);
		virtual void update(ccTime time);
		virtual CCObject* copyWithZone(CCZone* pZone);

	public:
		/** creates the action with a random seed, the grid size and the duration */
		static CCShuffleTiles* actionWithSeed(int s, const ccGridSize& gridSize, ccTime duration);

	protected:
		int			 m_nSeed;
		unsigned int m_nTilesCount;
		int			 *m_pTilesOrder;
		Tile		 *m_pTiles;
	};

	/** @brief CCFadeOutTRTiles action
	 Fades out the tiles in a Top-Right direction
	 */
	class CC_DLL CCFadeOutTRTiles : public CCTiledGrid3DAction
	{
	public:
		virtual float testFunc(const ccGridSize& pos, ccTime time);
		void turnOnTile(const ccGridSize& pos);
		void turnOffTile(const ccGridSize& pos);
		virtual void transformTile(const ccGridSize& pos, float distance);
		virtual void update(ccTime time);

	public:
		/** creates the action with the grid size and the duration */
		static CCFadeOutTRTiles* actionWithSize(const ccGridSize& gridSize, ccTime time);
	};

	/** @brief CCFadeOutBLTiles action.
	 Fades out the tiles in a Bottom-Left direction
	 */
	class CC_DLL CCFadeOutBLTiles : public CCFadeOutTRTiles
	{
	public:
		virtual float testFunc(const ccGridSize& pos, ccTime time);

	public:
		/** creates the action with the grid size and the duration */
        static CCFadeOutBLTiles* actionWithSize(const ccGridSize& gridSize, ccTime time);
	};

	/** @brief CCFadeOutUpTiles action.
	 Fades out the tiles in upwards direction
	 */
	class CC_DLL CCFadeOutUpTiles : public CCFadeOutTRTiles
	{
	public:
		virtual float testFunc(const ccGridSize& pos, ccTime time);
		virtual void transformTile(const ccGridSize& pos, float distance);

	public:
		/** creates the action with the grid size and the duration */
        static CCFadeOutUpTiles* actionWithSize(const ccGridSize& gridSize, ccTime time);
	};

	/** @brief CCFadeOutDownTiles action.
	 Fades out the tiles in downwards direction
	 */
	class CC_DLL CCFadeOutDownTiles : public CCFadeOutUpTiles
	{
	public:
		virtual float testFunc(const ccGridSize& pos, ccTime time);

	public:
		/** creates the action with the grid size and the duration */
        static CCFadeOutDownTiles* actionWithSize(const ccGridSize& gridSize, ccTime time);
	};

	/** @brief CCTurnOffTiles action.
	 Turn off the files in random order
	 */
	class CC_DLL CCTurnOffTiles : public CCTiledGrid3DAction
	{
	public:
		~CCTurnOffTiles(void);
		/** initializes the action with a random seed, the grid size and the duration */
		bool initWithSeed(int s, const ccGridSize& gridSize, ccTime duration);
		void shuffle(int *pArray, unsigned int nLen);
		void turnOnTile(const ccGridSize& pos);
		void turnOffTile(const ccGridSize& pos);

		virtual CCObject* copyWithZone(CCZone* pZone);
		virtual void startWithTarget(CCNode *pTarget);
		virtual void update(ccTime time);

	public:
		/** creates the action with the grid size and the duration */
		static CCTurnOffTiles* actionWithSize(const ccGridSize& size, ccTime d);
		/** creates the action with a random seed, the grid size and the duration */
		static CCTurnOffTiles* actionWithSeed(int s, const ccGridSize& gridSize, ccTime duration);

	protected:
		int				m_nSeed;
		unsigned int	m_nTilesCount;
		int				*m_pTilesOrder;
	};

	/** @brief CCWavesTiles3D action. */
	class CC_DLL CCWavesTiles3D : public CCTiledGrid3DAction
	{
	public:
		/** waves amplitude */
		inline float getAmplitude(void) { return m_fAmplitude; }
		inline void setAmplitude(float fAmplitude) { m_fAmplitude = fAmplitude; }

		/** waves amplitude rate */
		inline float getAmplitudeRate(void) { return m_fAmplitudeRate; }
		inline void setAmplitudeRate(float fAmplitudeRate) { m_fAmplitudeRate = fAmplitudeRate; }

		/** initializes the action with a number of waves, the waves amplitude, the grid size and the duration */
		bool initWithWaves(int wav, float amp, const ccGridSize& gridSize, ccTime duration);

		virtual CCObject* copyWithZone(CCZone* pZone);
		virtual void update(ccTime time);

	public:
		/** creates the action with a number of waves, the waves amplitude, the grid size and the duration */
		static CCWavesTiles3D* actionWithWaves(int wav, float amp, const ccGridSize& gridSize, ccTime duration);

	protected:
		int m_nWaves;
		float m_fAmplitude;
		float m_fAmplitudeRate;
	};

	/** @brief CCJumpTiles3D action.
	 A sin function is executed to move the tiles across the Z axis
	 */
	class CC_DLL CCJumpTiles3D : public CCTiledGrid3DAction
	{
	public:
		/** amplitude of the sin*/
		inline float getAmplitude(void) { return m_fAmplitude; }
		inline void setAmplitude(float fAmplitude) { m_fAmplitude = fAmplitude; }

		/** amplitude rate */
		inline float getAmplitudeRate(void) { return m_fAmplitudeRate; }
		inline void setAmplitudeRate(float fAmplitudeRate) { m_fAmplitudeRate = fAmplitudeRate; }

		/** initializes the action with the number of jumps, the sin amplitude, the grid size and the duration */
		bool initWithJumps(int j, float amp, const ccGridSize& gridSize, ccTime duration);
		virtual CCObject* copyWithZone(CCZone* pZone);
		virtual void update(ccTime time);

	public:
		/** creates the action with the number of jumps, the sin amplitude, the grid size and the duration */
        static CCJumpTiles3D* actionWithJumps(int j, float amp, const ccGridSize& gridSize, ccTime duration);

	protected:
		int m_nJumps;
		float m_fAmplitude;
		float m_fAmplitudeRate;
	};

	/** @brief CCSplitRows action */
	class CC_DLL CCSplitRows : public CCTiledGrid3DAction
	{
	public :
		/** initializes the action with the number of rows to split and the duration */
		bool initWithRows(int nRows, ccTime duration);

		virtual CCObject* copyWithZone(CCZone* pZone);
		virtual void update(ccTime time);
		virtual void startWithTarget(CCNode *pTarget);

	public:
		/** creates the action with the number of rows to split and the duration */
		static CCSplitRows* actionWithRows(int nRows, ccTime duration);

	protected:
		int m_nRows;
		CCSize m_winSize;
	};

	/** @brief CCSplitCols action */
	class CC_DLL CCSplitCols : public CCTiledGrid3DAction
	{
	public:
		/** initializes the action with the number of columns to split and the duration */
		bool initWithCols(int nCols, ccTime duration);

		virtual CCObject* copyWithZone(CCZone* pZone);
		virtual void update(ccTime time);
		virtual void startWithTarget(CCNode *pTarget);

	public:
		/** creates the action with the number of columns to split and the duration */
		static CCSplitCols* actionWithCols(int nCols, ccTime duration);

	protected:
		int m_nCols;
		CCSize m_winSize;
	};
} // end of namespace cocos2d

#endif // __ACTION_CCTILEDGRID_ACTION_H__
